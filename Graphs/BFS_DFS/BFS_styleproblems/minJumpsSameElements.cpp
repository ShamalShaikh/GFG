// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;
    queue<int>q;

    void addEdge(int v, int w);
    int minJumps(vector<int>&A);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

int Graph::minJumps(vector<int>&A)
{
    unordered_map<int,vector<int>>unmap;
    int n = A.size();
    for(int i=0;i<n;++i){
        unmap[A[i]].push_back(i);
    }
    
    int v = 0;
    int level = 0;
    visited[v] = true;
    q.push(v);
    int x;
    while(!q.empty()){
        int  currentQSize = q.size();
        while(currentQSize--){  
            x = q.front();
            q.pop();
            if(x == n-1){
                return level;
            }
            // move to (i-1), (i+1), (all same value elements)
            if(x-1>=0 &&A[x-1]!= A[x] && !visited[x-1]){
                    visited[x-1] = true;
                    q.push(x-1);
            }else if(x+1<n && A[x+1]!= A[x] && !visited[x+1]){
                    visited[x+1] = true;
                    q.push(x+1);
            }
            for(auto i : unmap[A[x]]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        level++;
    }
    return -1;
}

// Driver code
int main()
{
    // Given an array, create the graph
    vector<int>A = {7, 6, 9, 6, 9, 6, 9, 7};
    // {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};

    Graph g;

    cout << "Following is Breadth First Traversal (starting from vertex A[0]) \n";

    // cout<<g.BFSLevelFinder(0, 3)<<endl;

    cout<<g.minJumps(A);

    return 0;
}

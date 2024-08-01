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
    int BFSLevelFinder(int v, int X);
    int BFSLevelFinder2(int v, int X);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

int Graph::BFSLevelFinder(int v, int X)
{
    int level = 0;
    visited[v] = true;
    q.push(v);
    int x;
    while(!q.empty()){
        int  currentQSize = q.size();
        while(currentQSize--){  
            x = q.front();
            q.pop();
            if(x == X){
                return level;
            }
            for(auto i: adj[x]){
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


int Graph::BFSLevelFinder2(int v, int X)
{
    int level = 0;
    visited[v] = true;
    q.push(v);
    q.push(-1);
    int x;
    while(q.size() != 1){
        x = q.front();
        q.pop();
        if(x == X){
            return level;
        }
        if(x == -1){
            level++;
            q.push(-1);
        }
        else{
            for(auto i: adj[x]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    return -1;
}

// Driver code
int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 2);
    g.addEdge(2, 4);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";

    // cout<<g.BFSLevelFinder(0, 3)<<endl;

    cout<<g.BFSLevelFinder2(0, 3);

    return 0;
}

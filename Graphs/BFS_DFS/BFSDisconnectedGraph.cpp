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
    void BFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::BFS(int v)
{
    visited[v] = true;
    q.push(v);
    int x;
    while(!q.empty()){
        x = q.front();
        q.pop();
        cout<<x<<" ";
        for(auto i: adj[x]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

// Driver code
int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";

    g.BFS(0);

    return 0;
}

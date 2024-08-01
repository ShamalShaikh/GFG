// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <iostream>
#include <vector>
#include <map>
#include <list>
using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;

    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    // mark current node as visited
    visited[v] = true;
    cout<<v<<" ";

    // for (int neighbor : adj[v]) {
    // if (!visited[neighbor]) {
    //         DFS(neighbor);
    //     }
    // }

    for (auto it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (!visited[*it]) {
            DFS(*it);
        }
    }


    // for(int i = 0; i<adj[v].size(); ++i){
    //     if(!visited[adj[v][i]]){             // if you use a vector instead of list<int>
    //         DFS(i);
    //     }
    // }
}

// Driver code
int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";

    g.DFS(2);

    return 0;
}

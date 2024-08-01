// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <stack>
using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;


    void addEdge(int v, int w);
    void DFS();
    void DFSUtil(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v)
{
    // mark current node as visited
    stack<int>s;
    s.push(v);
    int x;
    while(!s.empty()){
        x = s.top();
        s.pop();
        if (!visited[x])
        {
            cout << x << " ";
            visited[x] = true;
        }
        for (auto i : adj[x])
            if (!visited[i])
                s.push(i);
    }
}


void Graph::DFS()
{
   for (int i = 0; i < adj.size(); i++)
        if (!visited[i])
            DFSUtil(i);
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

    g.DFS();

    return 0;
}

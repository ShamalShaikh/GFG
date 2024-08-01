#include<iostream>
#include<vector>
#include<list>
using namespace std;

void printGraph(vector<vector<int>>& G){
    int n = G.size();
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<G[i][j]<<" ";
        }
        cout<<'\n';
    }
}

vector<vector<int>> createAdjMatrix(int n){
    cout<<"Press 1 if there is an edge between u and v: \n";
    cout<<"Press 0 if not \n";
    vector<vector<int>> G (n, vector<int>(n,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<"["<<(i+1)<<"] ---- ["<<(j+1)<<"]?";
            cin>>G[i][j];
        }
    }
    printGraph(G);
    return G;
}

void printAdjListGraph(vector<list<int>>& G, int n){
    // Print the adjacency List
    for (int i = 0; i < n; ++i) {
          cout << i << " -> ";
        for(auto j: G[i]){
            cout<<j<<" ";
        }
        // for (int j = 0; j < G[i].size(); ++j) {
        //     cout << G[i][j] << " ";
        // }
        cout << endl;
    }
}

vector<list<int>> createAdjList(int n){
    vector<list<int>> G (n);
    int u, v, m;
    cout<<"enter number of edges in the graph: \n";
    cin>>m;
    for(int i=0;i<m;++i){
            cin>>u>>v;
            if(u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid vertex index. Vertices should be between 0 and " << n-1 << ".\n";
            --i; // Adjust the loop counter to re-enter the edge
            continue;
        }
            G[u].push_back(v);
            G[v].push_back(u);
    }

    printAdjListGraph(G, n);
    return G;
}

int main(){
    // if want to create the graph and not want to change again and again:
    // vector<vector<int> > G = { { 0, 1, 0, 0 },
    //                                { 1, 0, 1, 0 },
    //                                { 0, 1, 0, 1 },
    //                                { 0, 0, 1, 0 } };
    
    // number of vertices in the graph
    int n; 
    cout<<"How many vertices are in the graph?\n";
    cin>>n;
    vector<list<int>> G;
    // G = createAdjMatrix(n);
    G = createAdjList(n);
    return 0;
}
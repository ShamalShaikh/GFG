// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include<tuple>
using namespace std;

class Graph {
public:
    map<tuple<int,int,int>, bool> visited;
    queue<tuple<int,int,int,int>>q;

    int BFS(vector<vector<char>>& grid, tuple<int,int,int> v, int i2, int j2);
};

int Graph::BFS(vector<vector<char>>& grid, tuple<int,int,int> v, int i2, int j2)
{
    int coins = grid[get<0>(v)][get<1>(v)]-'0';
    auto newv = tuple_cat(v, make_tuple(coins));
    visited[v] = true;
    q.push(newv);
    tuple<int,int,int, int> x;
    int time = 0;
    int minTime = INT_MAX;
    vector<vector<int> > dir = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            x = q.front();
            q.pop();
            int x1 = get<0>(x), y1 = get<1>(x), k = get<2>(x), currCoins=get<3>(x);
            if (time >= minTime) {
                break;
            }
            if(x1 == i2 && y1 == j2)
            {
                minTime = min(time, minTime);
                coins = max(coins, currCoins);
            }

            for (int k = 0; k < 4; k++) 
            {
                int newX = x1 + dir[k][0];
                int newY = y1 + dir[k][1];
 
                if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[newX].size() && visited[make_tuple(newX, newY, grid[newX][newY] == '*'? k - 1: k)]== false) 
                {
                    if (grid[newX][newY] == '*' && k > 0) {
                        q.push({ newX, newY, k - 1,currCoins });
                    }
                    else if (grid[newX][newY] != '*') {
                        q.push({ newX, newY, k,currCoins+ (grid[newX][newY]- '0') });
                    }
                    if (newX != i2 && newY != j2)
                        visited[make_tuple(newX,newY,grid[newX][newY] == '*'? k - 1: k)]= true;
                }
            }
        }
    }
    return coins;
}

// Driver code
int main()
{
    vector<vector<char> > grid = { { '*', '0', '1', '1' }, 
                                    { '0', '0', '*', '*' }, 
                                    { '0', '*', '*', '*' },
                                    { '0', '0', '0', '1' }};
                                // { { '*', '0', '1', '2' },
                                //    { '0', '0', '*', '*' },
                                //    { '*', '*', '6', '8' },
                                //    { '0', '0', '0', '1' } };
 
    int i1 = 0, j1 = 2;
    int i2 = 3, j2 = 3;
    int k = 1;

    Graph g;

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";

    cout<<g.BFS(grid, make_tuple(i1, j1, k), i2,j2);

    return 0;
}

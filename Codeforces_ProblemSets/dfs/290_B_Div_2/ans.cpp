#include<iostream>
#include<vector>

using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool isValid(int r, int c)
{
    return r>=0 && r < n && c>=0 && c < m;
}

bool dfs(int r, int c, int pr, int pc)
{
    visited[r][c] = true;

    // Explore neighbors
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i], nc = c + dc[i];

        // Check if the neighbor is within the grid
        if(isValid(nr, nc))
        {
            // Check if they are same char
            if(grid[nr][nc] == grid[r][c])
            {
                // Check if the neighbor is the parent
                if(nr == pr && nc == pc) continue;

                // Check if it is already visited
                if(visited[nr][nc]) return true; // Cycle detected
                else
                {
                    if(dfs(nr, nc, r, c)) return true;
                }
            }
        }
    }
    // No cycle found starting from this path 
    return false;
}

int main()
{
    cin>>n>>m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++) cin>>grid[i];

    bool found_cycle = false;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j])
            {
                if(dfs(i, j, -1, -1))
                {
                    found_cycle = true;
                    break;
                } 
            }
        }
        if(found_cycle) break;
    }
    if(found_cycle) cout <<"Yes";
    else cout<<"No";

    return 0;
}

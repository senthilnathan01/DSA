#include<iostream>
#include<vector>

using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool isValid(int nr, int nc, int n, int m)
{
    return nr >= 0 && nr < n && nc >= 0 && nc < m;
}

int dfs(int r, int c, int pr, int pc, vector<vector<int>> &grid, vector<vector<bool>> &visited, int n, int m)
{
    visited[r][c] = true;

    int new_vol = grid[r][c];
    int addition = 0;
    for(int i = 0; i < 4; i++)
    {
        int nr = r + dr[i], nc = c + dc[i];
        if(isValid(nr, nc, n, m))
        {
            if(grid[nr][nc] == 0)
            {
                visited[nr][nc] = true;
                continue;
            }

            if(!visited[nr][nc])    addition += dfs(nr, nc, r, c, grid, visited, n, m);
        }
    }
    return new_vol + addition;
}

int solve()
{
    int n, m; cin>>n>>m;
    vector<vector<int>> grid (n, vector<int>(m));
    vector<vector<bool>> visited (n, vector<bool>(m, false));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
            if(grid[i][j] == 0) visited[i][j] = true;
        }
    }
    
    int vol = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j])
            {
                vol = max(dfs(i, j, -1, -1, grid, visited, n, m), vol);
            }
        }
    }

    return vol;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}

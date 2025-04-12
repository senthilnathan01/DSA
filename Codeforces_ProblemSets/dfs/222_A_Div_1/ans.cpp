#include<iostream>
#include<vector>
using namespace std;

#define CODE ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
int n, m, k;
vector<string> grid; //The maze grid
vector<vector<bool>> visited; // To keep track of the visited cells during DFS
vector<pair<int,int>> cells_to_modify; // Stores empty cells in post-order DFS traversal

// Direction arrays for moving up, down, left, right
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

// DFS function
void dfs(int r, int c)
{
    // 1. Check the boundaries
    if(r<0 || r >= n || c < 0 || c >= m) return;

    // 2. Check if it is a wall
    if(grid[r][c] == '#') return;

    // 3. Check if already visited
    if(visited[r][c]) return;

    visited[r][c] = true;

    for(int i = 0; i < 4; i++)
    {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        dfs(next_r, next_c);
    }

    // 4. Add the current cell to our list *after* visiting all its neighbors
    // This is post order traversal. The cells added first here are the ones
    // finished last in the DFS 
    cells_to_modify.push_back({r,c});
}

int main()
{
    CODE
    cin>>n>>m>>k;

    grid.resize(n);
    visited.resize(n, vector<bool>(m, false));

    int start_row = -1, start_col = -1;
    int total_empty_cells = 0;

    // Read the grid from input
    for(int i = 0; i < n; i++)
    {
        cin>>grid[i];
        // Find the first cell to start DFS
        // Count the total number of empty cells
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j]=='.')
            {
                total_empty_cells++;
                if(start_row == -1)
                {
                    // store the coord of the first '.' found
                    start_row = i; start_col = j;
                }
            }
        }
    }
    
    if(start_row != -1)
    {
        dfs(start_row, start_col);
    }

    // Now, the 'cells_to_modify' contains all 's' empty cells
    // Because of the post order addition, the cells visited *last*
    // by the overall DFS exploration appear at the *beginning* of the vector
    for(int i = 0; i < k; i++)
    {
        pair<int, int> cell = cells_to_modify[i];
        grid[cell.first][cell.second] = 'X';
    }

    for(int i = 0; i < n; i++) cout<<grid[i]<<"\n";

    return 0;
}

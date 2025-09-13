/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

LINK: https://leetcode.com/problems/number-of-islands/description/
*/

// DFS
class Solution {
public:
    vector<vector<bool>> visited;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(int i, int j, int m, int n, vector<vector<char>> &grid){
        visited[i][j] = true;

        for(int dir = 0; dir < 4; dir++){
            int nr = i + dr[dir], nc = j + dc[dir];
            if(nr<0 || nr >= m || nc <0 || nc >=n) continue;
            if(visited[nr][nc] == false && grid[nr][nc]=='1') dfs(nr, nc, m, n, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]==false && grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, m, n, grid);
                }
            }
        }
        return cnt;
    }
};

// BFS - to avoid recursion stack
// Also avoiding visited array (only if modifying grid is fine)
// Basically add the land to a queue and sink 
// Process the queue and add its neighbours to the queue and sink them
// Just keeping doing this until there is nothing in the queue
class Solution {
public:
    vector<vector<bool>> visited;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void bfs(int i, int j, int m, int n, vector<vector<char>> &grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0'; // sink it

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int dir = 0; dir < 4; dir++){
                int nr = r + dr[dir], nc = c + dc[dir];
                if(nr < 0 || nr >= m || nc < 0 || nc >=n) continue;
                if(grid[nr][nc]=='1'){
                    q.push({nr, nc});
                    grid[nr][nc] = 0;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited.assign(m, vector<bool>(n, false));
        int cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j]==false && grid[i][j] == '1'){
                    cnt++;
                    grid[i][j] = '0'; // sink it
                    bfs(i, j, m, n, grid);
                }
            }
        }
        return cnt;
    }
};

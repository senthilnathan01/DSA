/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. 
You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west 
if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

LINK: https://leetcode.com/problems/pacific-atlantic-water-flow/description/
*/

class Solution {
public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(int r, int c, int m, int n, vector<vector<bool>> &vis, vector<vector<int>> &heights){
        vis[r][c] = true;
        for(auto [dr, dc]: dirs){
            int nr = r + dr, nc = c + dc;
            if(nr < 0 || nr >=m || nc <0 || nc>=n) continue;
            if(vis[nr][nc] || heights[nr][nc]<heights[r][c]) continue;
            dfs(nr, nc, m, n, vis, heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> p(m, vector<bool>(n, false));
        vector<vector<bool>> a(m, vector<bool>(n, false));
        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            dfs(i, 0, m, n, p, heights);
            dfs(i, n-1, m, n, a, heights);
        }

        for(int j = 0; j < n; j++){
            dfs(0, j, m, n, p, heights);
            dfs(m-1, j, m, n, a, heights);
        }

        for(int i= 0; i < m; i++){
            for(int j = 0; j < n; j++) if(p[i][j] && a[i][j]) res.push_back({i, j});
        }
        return res;
    }
};

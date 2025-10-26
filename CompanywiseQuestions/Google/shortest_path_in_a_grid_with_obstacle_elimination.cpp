/*
You are given an m x n integer matrix grid where each cell is either 0 (empty) or 1 (obstacle). 
You can move up, down, left, or right from and to an empty cell in one step.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner 
(m - 1, n - 1) given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

LINK: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/
*/

class Solution {
public:
    // down, right, up, left
    vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int ans = INT_MAX;

    void dfs(int r, int c, int m, int n, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp, int k, int steps, int obsCnt){
        // Base Case
        if(r==m-1 && c==n-1){
            if(obsCnt <=k) ans = min(ans, steps);
            return;
        }

        // Ya, we don't want this
        if(obsCnt>k) return;

        // Heuristic Prune: Even with manhattan distance we can't beat current minimum ans
        int manhattanDist = (m-1-r) + (n-1-c);
        if(steps + manhattanDist >= ans) return;

        // Memoization Prune: if the state (r, c, obsCnt) was reached in fewer steps no need to explore again
        if(dp[r][c][obsCnt] <= steps) return;

        // Let's start now
        dp[r][c][obsCnt] = steps;
        int val = grid[r][c];
        // marking current cell as visited by keeping it as -1 (u can keep anything other than 0 or 1)
        grid[r][c] = -1;

        // do dfs through all 4 directions
        for(auto dir: dirs){
            int nr = r + dir.first, nc = c + dir.second;
            if(0<= nr && nr <= m-1 && 0<=nc && nc <= n-1 && grid[nr][nc]!=-1){
                if(grid[nr][nc]==1){
                    dfs(nr, nc, m, n, grid, dp, k, steps+1, obsCnt + 1);
                }
                else dfs(nr, nc, m, n, grid, dp, k, steps + 1, obsCnt);
            }
        }

        // Backtrack (unmark it/make it as not visited)
        grid[r][c] = val;
    }

    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(); 
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n));
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++) dp[r][c].assign(k+1, INT_MAX);
        }

        dfs(0, 0, m, n, grid, dp, k, 0, 0);

        return ans==INT_MAX ? -1: ans;
    }
};


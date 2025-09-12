/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

LINK: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
*/

class Solution {
public:
    vector<vector<int>> dfsTable;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int dfs(int r, int c, int m, int n, vector<vector<int>> &matrix){
        if(dfsTable[r][c]!=-1) return dfsTable[r][c];

        int curr = 1;
        for(int dir = 0; dir < 4; dir++){
            int nr = r + dr[dir], nc = c + dc[dir];
            if(nr<0 || nr>=m || nc<0 || nc>=n || matrix[nr][nc] <= matrix[r][c]) continue;
            curr = max(curr, 1 + dfs(nr, nc, m, n, matrix));
        }
        return dfsTable[r][c] = curr;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dfsTable.assign(m, vector<int>(n, -1));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) ans = max(ans, dfs(i, j, m, n, matrix));
        }
        return ans;
    }
};

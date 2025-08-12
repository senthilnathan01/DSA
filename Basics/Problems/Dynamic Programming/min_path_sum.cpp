/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

LeetCode Link: https://leetcode.com/problems/minimum-path-sum/description/
*/

class Solution {
public:
    int dr[2] = {-1, 0};
    int dc[2] = {0, -1};
    int dp(int r, int c, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &SumMat)
    {
        if(r==0 && c == 0)
        {
            return SumMat[0][0] = grid[0][0];
        }

        if(SumMat[r][c]!=-1) return SumMat[r][c];

        int ans = INT_MAX;
        for(int i = 0; i < 2; i++)
        {
            int new_r = r + dr[i], new_c = c + dc[i];
            if(new_r>=0 && new_r<m && new_c>=0 && new_c < n)
            {
                ans = min(ans, dp(new_r, new_c, m, n, grid, SumMat));
            }
        }
        return SumMat[r][c] = ans + grid[r][c];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> SumMat(m, vector<int>(n, -1));
        return dp(m-1, n-1, m, n, grid, SumMat);
    }
};

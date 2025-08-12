/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 10^9.

LeetCode Link: https://leetcode.com/problems/unique-paths/description/
*/

class Solution {
public:
    int dr[2]={1, 0};
    int dc[2]={0, 1};
    vector<vector<int>> ways;
    int dfs(int r, int c, int m, int n, vector<vector<int>> &obstacleGrid)
    {
        if(r==m-1 && c==n-1)
        {
            return 1;
        }

        if(ways[r][c]!=-1) return ways[r][c];

        int curr_count = 0;
        for(int i = 0;i<2; i++)
        {
            int new_r = r + dr[i], new_c = c + dc[i];
            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n && obstacleGrid[new_r][new_c]!=1)
            {
                curr_count += dfs(new_r, new_c, m, n, obstacleGrid);
            }
        }
        return ways[r][c] = curr_count; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0]==1) return 0;

        ways.assign(m, vector<int>(n, -1));
        return dfs(0, 0, m, n, obstacleGrid);        
    }
};

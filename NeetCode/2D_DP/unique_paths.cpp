/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
  The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

LINK: https://leetcode.com/problems/unique-paths/description/
*/

// DFS Approach
class Solution {
public:
    int dr[2] = {1, 0};
    int dc[2] = {0, 1};
    vector<vector<int>> ways;
    int dfs(int r, int c, int m, int n){
        if(r==m-1 && c==n-1) return 1;
        if(ways[r][c]!=-1) return ways[r][c];
        int cnt = 0;
        for(int dir = 0; dir < 2; dir++){
            int nr = r + dr[dir], nc = c + dc[dir];
            if(0<=nr && nr < m && 0<=nc && nc < n) cnt += dfs(nr, nc, m, n);
        }
        return ways[r][c] = cnt;
    }

    int uniquePaths(int m, int n) {
        ways.assign(m, vector<int>(n, -1));
        return dfs(0, 0, m, n);
    }
};

// Tabulation Approach
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int j = 0; j < n; j++) dp[0][j] = 1;
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++) dp[i][j] = dp[i-1][j] + dp[i][j-1];
        } 
        return dp[m-1][n-1];
    }
};

// You know not surprisingly this is Pascal's Triangle problem!
// To see the pattern, tilt the grid by 45 degrees
// U r basically adding from the right just above and the left just above

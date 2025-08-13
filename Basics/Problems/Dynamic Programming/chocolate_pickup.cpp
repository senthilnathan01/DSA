/*
Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.

If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.

Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

Link: https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885?leftPanelTabValue=PROBLEM
*/

#include <bits/stdc++.h> 
int f(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid. vector<vector<vector<int>>> &dp)
{
    if(j1<0 || j2<0 || j1>=c || j2 >= c)
    {
        return -1e8;
    }
    // Base Case
    if(i==r-1)
    {
        if(j1==j2) return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    // Other Cases
    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= 1; dj1++)
    {
        for(int dj2 = -1; dj2 <= 1; dj2++)
        {
            int val = 0;
            if(j1 == j2) val = grid[i][j1];
            else val = grid[i][j1] + grid[i][j2];
            val += f(i+1, j1 + dj1, j2 + dj2, r, c, grid, dp);
            maxi = max(maxi, val);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return f(0, 0, c-1, r, c, grid, dp);
}

// Tabulation Approach
#include <bits/stdc++.h> 

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, 0)));

    // Base Case
    for(int j1 = 0; j1<c; j1++)
    {
        for(int j2 = 0; j2 < c; j2++)
        {
            if(j1==j2) dp[r-1][j1][j2] = grid[r-1][j1];
            else dp[r-1][j1][j2] = grid[r-1][j1] + grid[r-1][j2];
        }
    }

    for(int i = r-2; i>=0; i--)
    {
        for(int j1 = 0; j1<c; j1++)
        {
            for(int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;
                for(int dj1 = -1; dj1<=1; dj1++)
                {
                    for(int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int val = 0;
                        if(j1==j2) val = grid[i][j1];
                        else val = grid[i][j1] + grid[i][j2];
                        if(j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)
                            val += dp[i+1][j1 + dj1][j2 + dj2];
                        else val += -1e8;
                        maxi = max(maxi, val);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][c-1];
}

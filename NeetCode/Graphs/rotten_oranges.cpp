/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

LINK: https://leetcode.com/problems/rotting-oranges/description/
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size();
        for(int i =0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(fresh==0) return 0;

        int t = -1;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0,-1}, {0, 1}};
        while(!q.empty()){
            t++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto [r, c] = q.front();
                q.pop();
                for(auto [dr, dc]: dirs){
                    int nr = r + dr, nc = c + dc;
                    if(0<=nr && nr < m && 0<=nc && nc<n && grid[nr][nc]==1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
        }

        return (fresh==0) ? t : -1;
    }
};

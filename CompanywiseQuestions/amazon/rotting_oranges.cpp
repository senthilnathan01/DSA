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
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rotten;
        int m = grid.size();
        int n = grid[0].size();
        int num_fresh = 0;
        for(int i =0; i< m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==2) rotten.push({i, j});
                if(grid[i][j]==1) num_fresh++;
            }
        }

        int t = 0;
        while(!rotten.empty()){
            int sz = rotten.size();
            bool rot_operation = false;
            for(int i =0; i < sz; i++){
                auto [r, c] = rotten.front(); rotten.pop();
                for(auto &[dr, dc]: dirs){
                    int nr = dr + r;
                    int nc = dc + c;
                    if(nr<0 || nr >= m || nc < 0 || nc >= n || grid[nr][nc]!=1) continue;
                    rot_operation = true;
                    grid[nr][nc]=2;
                    num_fresh--;
                    rotten.push({nr, nc});

                }
            }
            if(rot_operation) t++;
        }
        if(num_fresh==0) return t;
        return -1;
    }
};

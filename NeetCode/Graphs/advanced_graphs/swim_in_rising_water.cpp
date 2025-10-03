/*
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. 
  You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

  LINK: https://leetcode.com/problems/swim-in-rising-water/description/
*/

class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    vector<pair<int, int>> dirs = {{0,1}, {0, -1}, {-1, 0}, {1, 0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> times(n, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({grid[0][0], {0, 0}});
        times[0][0] = grid[0][0];

        while(!pq.empty()){
            auto [t,rc] = pq.top(); pq.pop();
            auto [r,c] = rc;

            if(r==n-1 && c == n-1) return t;

            for(auto [dr,dc]: dirs){
                int nr = r + dr, nc = c + dc;
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                int newt = max(t, grid[nr][nc]);
                if(times[nr][nc]>newt){
                    times[nr][nc] = newt;
                    pq.push({newt, {nr, nc}});
                }
            }
        }
        return -1;
    }
};

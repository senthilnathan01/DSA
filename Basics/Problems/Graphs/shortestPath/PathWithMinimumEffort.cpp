/*
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, 
where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, 
(0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can 
move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/

class Solution {
public:
    // {diff, {row, col}}
    typedef pair<int, pair<int, int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<P, vector<P>, greater<P>> pq;
        
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist (n, vector<int> (m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1) return diff;

            for(int i = 0; i < 4; i++)
            {
                int newR = row + delRow[i];
                int newC = col + delCol[i];

                if(newR>=0 && newR<n && newC >= 0 && newC < m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[newR][newC]), diff);
                    if(newEffort < dist[newR][newC])
                    {
                        dist[newR][newC] = newEffort;
                        pq.push({newEffort, {newR, newC}});
                    }
                }
            }
        }
        return 0;
    }
};

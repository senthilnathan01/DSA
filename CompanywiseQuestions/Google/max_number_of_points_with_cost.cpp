/*
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.

LINK: https://leetcode.com/problems/maximum-number-of-points-with-cost/description/
*/
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> prev(points[0].begin(), points[0].end());
        for(int r =1; r < m; r++){
            vector<long long> left(n), right(n), curr(n);

            // form left
            left[0]=prev[0];
            for(int c = 1; c < n; c++) left[c] = max(left[c-1]-1, prev[c]);

            // form right
            right[n-1] = prev[n-1];
            for(int c = n-2; c>=0; c--) right[c] = max(right[c+1]-1, prev[c]);

            // form curr
            for(int c = 0; c <n; c++) curr[c] = points[r][c] + max(left[c], right[c]);

            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};

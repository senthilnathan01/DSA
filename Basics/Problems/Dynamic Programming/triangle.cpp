/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, 
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

LeetCode Link: https://leetcode.com/problems/triangle/
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        vector<vector<int>> minSum;
        for(int row = 0; row <rows; row++)
        {
            vector<int> triangleRow(row+1, INT_MAX);
            minSum.push_back(triangleRow);
        }
        minSum[0][0] = triangle[0][0];

        for(int row = 0; row < rows-1; row++)
        {
            for(int idx = 0; idx <= row; idx++)
            {
                minSum[row+1][idx] = min(minSum[row+1][idx], minSum[row][idx] + triangle[row+1][idx]);
                minSum[row+1][idx+1] = min(minSum[row+1][idx+1], minSum[row][idx] + triangle[row+1][idx+1]); 
            }
        }
        
        return *min_element(minSum[rows-1].begin(), minSum[rows-1].end());
    }
};

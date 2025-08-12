/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is 
either directly below or diagonally left/right. Specifically, the next element from position (row, col) 
will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

LeetCode Link: https://leetcode.com/problems/minimum-falling-path-sum/description/
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> minSum(n, vector<int>(n, INT_MAX));
        minSum[0] = matrix[0];
        for(int row = 0; row <= n-2; row++)
        {
            for(int idx = 0; idx < n; idx++)
            {
                if(idx>=1) minSum[row+1][idx-1] = min(minSum[row+1][idx-1], minSum[row][idx] + matrix[row+1][idx-1]);
                if(idx<=n-2) minSum[row+1][idx+1] = min(minSum[row+1][idx+1], minSum[row][idx] + matrix[row+1][idx+1]);
                minSum[row+1][idx] = min(minSum[row+1][idx], minSum[row][idx] + matrix[row+1][idx]);
            }
        }
        return *min_element(minSum[n-1].begin(), minSum[n-1].end());
    }
};

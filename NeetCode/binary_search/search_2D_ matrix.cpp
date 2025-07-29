/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Leetcode Link: https://leetcode.com/problems/search-a-2d-matrix/description/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int num_rows = matrix.size(), num_cols = matrix[0].size();
        // box_no = row_no*num_cols + col_no;
        int low = 0;
        int high = num_rows * num_cols -1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            // row_no = mid/num_cols
            // col_no = mid%num_cols
            int num = matrix[mid/num_cols][mid%num_cols];
            if(num==target) return true;
            else if(num < target) low = mid + 1;
            else high = mid - 1;
        }
        return false;
    }
};

#include<iostream>
#include<vector>

using namespace std;

/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

// We use binary search to solve this problem

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Find the appropriate row using binary search.
    int low_row = 0;
    int high_row = rows - 1;
    int mid_row;
    while (low_row <= high_row) {
        mid_row = low_row + (high_row - low_row) / 2;
        if (matrix[mid_row][0] == target) {
            return true; // Target found in the first column
        } else if (matrix[mid_row][0] < target) {
            if (mid_row < rows - 1 && matrix[mid_row + 1][0] > target) {
                break; // Target is in this row
            } else {
                low_row = mid_row + 1; // Target is in a lower row
            }
        } else {
            high_row = mid_row - 1; // Target is in a higher row
        }
    }

    // Perform binary search in the chosen row.
    int low_col = 0;
    int high_col = cols - 1;
    while (low_col <= high_col) {
        int mid_col = low_col + (high_col - low_col) / 2;
        if (matrix[mid_row][mid_col] == target) {
            return true; // Target found
        } else if (matrix[mid_row][mid_col] < target) {
            low_col = mid_col + 1; // Target is in the right part of the row
        } else {
            high_col = mid_col - 1; // Target is in the left part of the row
        }
    }

    return false; // Target not found
}

int main() {
    vector<vector<int>> arr = {
        {0,1,2},
        {4,8,10},
        {15,16,17}
    };
    cout<<searchMatrix(arr, 10)<<endl;
}

// OUTPUT:
// 1


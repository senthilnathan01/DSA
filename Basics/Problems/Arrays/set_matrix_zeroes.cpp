#include<bits/stdc++.h>
using namespace std;

/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.
*/

// First Iteration

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> colsWithZero;
        set<int> rowsWithZero;

        int numRows = matrix.size();
        int numCols = matrix[0].size();

        // Find all the zero elements
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j < numCols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    colsWithZero.insert(j);
                    rowsWithZero.insert(i);
                }
            }
        }

        for(auto row: rowsWithZero)
        {
            matrix[row].assign(numCols, 0);
        }

        for(auto col: colsWithZero)
        {
            for(int i = 0; i < numRows; i++)
            {
                matrix[i][col] = 0;
            }
        }
    }
};
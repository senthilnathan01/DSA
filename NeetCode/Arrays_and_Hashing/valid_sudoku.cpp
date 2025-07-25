/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.

Leetcode Link: https://leetcode.com/problems/valid-sudoku/description/
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, set<char>> inRow, inCol, inBox;
        for(int r = 0; r < 9; r++)
        {
            int row_no = r/3;
            for(int c = 0; c < 9; c++)
            {
                int col_no = c/3;
                int box_no = 3*row_no + col_no;
                if(board[r][c]=='.') continue;

                if(!inRow[r].insert(board[r][c]).second) return false;
                if(!inCol[c].insert(board[r][c]).second) return false;
                if(!inBox[box_no].insert(board[r][c]).second) return false;
            }
        }
        return true;
    }
};

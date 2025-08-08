/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

LeetCode Link: https://leetcode.com/problems/sudoku-solver/description/
*/

// Approach 1:
// But takes a lot of time
// Check out approach to see the optimised version
class Solution {
public:
    void populate(vector<set<int>> &row_nums, vector<set<int>> &col_nums, 
    vector<set<int>> &box_nums, vector<vector<char>>& board)
    {
        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                char ch = board[r][c];
                if(ch !='.')
                {
                    int box_no = (r/3)*3 + (c/3);

                    row_nums[r].insert(ch-'0');
                    col_nums[c].insert(ch-'0');
                    box_nums[box_no].insert(ch-'0');
                }
            }
        }
    }

    bool isValid(int num, int r, int c, vector<set<int>> &row_nums, vector<set<int>> &col_nums, 
    vector<set<int>> &box_nums)
    {
        return (row_nums[r].count(num)==0 && col_nums[c].count(num)==0 && box_nums[(r/3)*3 + (c/3)].count(num)==0); 
    }

    bool backtrackRow(int r, vector<vector<char>>& board, vector<set<int>> &row_nums, vector<set<int>> &col_nums, vector<set<int>> &box_nums)
    {
        if(r == 9) return true;

        return backtrackCol(r, 0, board, row_nums, col_nums, box_nums);
    }

    bool backtrackCol(int r, int c, vector<vector<char>>& board, vector<set<int>> &row_nums, vector<set<int>> &col_nums, vector<set<int>> &box_nums)
    {
        if(c == 9) return backtrackRow(r + 1, board, row_nums, col_nums, box_nums);

        if(board[r][c] != '.')
        {
            if(backtrackCol(r, c + 1, board, row_nums, col_nums, box_nums)) return true;
        }
        else
        {
            for(int num = 1; num <= 9; num++)
            {
                if(!isValid(num, r, c, row_nums, col_nums, box_nums)) continue;

                row_nums[r].insert(num);
                col_nums[c].insert(num);
                box_nums[(r/3)*3 + (c/3)].insert(num);

                board[r][c] = num + '0';    

                if(backtrackCol(r, c + 1, board, row_nums, col_nums, box_nums)) return true;

                row_nums[r].erase(num);
                col_nums[c].erase(num);
                box_nums[(r/3)*3 + (c/3)].erase(num);

                board[r][c] = '.';    
            } 
        }
        return false;     
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<set<int>> row_nums(9), col_nums(9), box_nums(9);
        populate(row_nums, col_nums, box_nums, board);

        if(backtrackRow(0, board, row_nums, col_nums, box_nums)) return;
    }
};

// Approach 2:
// What went wrong in approach 1?
// Optimisations done:
/*
  1. Replaced std::set<int> with std::array<bool, 10> or std::bitset<10>

O(1) lookup, insert, erase instead of O(log n).

  2. Precomputed empty cell positions:

Instead of scanning row/col repeatedly, made a vector of coordinates of empty cells once,
then backtrack through that vector.

  3. Use a single backtrack(idx) instead of two nested functions:

Passing (row, col) around in separate functions costs extra recursion overhead.
If you pre-store empty cell positions, idx just moves from 0 to empty_count-1.

  4. Inline isValid into the backtracking loop
Small performance gain by avoiding function call overhead.
*/

// Result:
// Runtime: 2000 ms -> 80 ms
// Reduction: 96%

class Solution {
    vector<array<bool, 10>> row, col, box;
    vector<pair<int,int>> emptyCells;
public:
    void solveSudoku(vector<vector<char>>& board) {
        row.assign(9, {});
        col.assign(9, {});
        box.assign(9, {});

        // populate trackers and list empty cells
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    int num = board[r][c] - '0';
                    row[r][num] = col[c][num] = box[(r/3)*3 + (c/3)][num] = true;
                } else {
                    emptyCells.push_back({r, c});
                }
            }
        }
        backtrack(0, board);
    }

    bool backtrack(int idx, vector<vector<char>>& board) {
        if (idx == emptyCells.size()) return true;
        auto [r, c] = emptyCells[idx];
        int b = (r/3)*3 + (c/3);

        for (int num = 1; num <= 9; num++) {
            if (!row[r][num] && !col[c][num] && !box[b][num]) {
                row[r][num] = col[c][num] = box[b][num] = true;
                board[r][c] = num + '0';
                if (backtrack(idx + 1, board)) return true;
                row[r][num] = col[c][num] = box[b][num] = false;
                board[r][c] = '.';
            }
        }
        return false;
    }
};

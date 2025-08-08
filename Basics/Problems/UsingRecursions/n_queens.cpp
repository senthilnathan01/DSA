/*
N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

LeetCode Link: https://leetcode.com/problems/n-queens/description/
*/

/*
Ok, let's plan:
For a queen to not attack another queen, the other queen 
should not be in the same row or in the same column, or along the diagonals
Three simple rules!

We gotta return all the possible matrices

I saw the example, I see a pattern to solve this

Initial thought is that TC = O(N!) which is high but with cell elimination it can come down

It's ok, let's try it out and see if we get TLE

Approach:
Iterate through each row and fill the available cell (and next available cell the next time) 
with the queen 
Maintain two vectors(for rows and for columns) to store info about the cells that are not available
Not gonna use matrix (n^2 size) as marking unavailability takes time
How do we manage diagonals?
If u observe-> the row = col along \ and can be represented by one number (row - col + n + 1)
row + col is constant along / and can be represented by one number (row + col)
We can use this to easily store it
*/ 

class Solution {
public:
    void backtrack(int row, int n, vector<vector<string>> &ans, vector<string> &board, 
    vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2)
    {
        if(row == n)
        {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(cols[col] || diag1[row+col] || diag2[row-col + n - 1]) continue;

            board[row][col] = 'Q';
            cols[col] = diag1[row+col] = diag2[row-col+n-1] = true;

            backtrack(row + 1, n, ans, board, cols, diag1, diag2);

            // Undo
            board[row][col] = '.';    
            cols[col] = diag1[row+col] = diag2[row-col+n-1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // Initializing the board
        vector<string> board(n, string(n, '.'));

        // Unavailability markers
        vector<bool> cols(n, false);

        // (n + n-1 diagonals)
        // "/" Coming from top left 0, 1, ...
        // diag1[row + col]
        vector<bool> diag1(2*n - 1, false); 

        // "\" Coming from top right 0, 1, ....
        // diag2[row - col + n - 1]
        vector<bool> diag2(2*n - 1, false); 

        backtrack(0, n, ans, board, cols, diag1, diag2);

        return ans;
    }
};

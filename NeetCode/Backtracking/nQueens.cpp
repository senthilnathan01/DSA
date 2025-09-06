/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

LINK: https://leetcode.com/problems/n-queens/description/
*/

class Solution {
public:
    vector<bool> diag1;
    vector<bool> diag2;
    vector<bool> col;
    vector<vector<string>> ans;

    void backtrack(int r, int n, vector<string> &board){
        if(r==n){
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++){
            if(col[c] || diag1[r+c] || diag2[r-c+n-1]) continue;

            board[r][c] = 'Q';
            col[c] = diag1[r+c] = diag2[r-c+n-1] = true;
            backtrack(r+1, n, board);
            board[r][c] = '.';
            col[c] = diag1[r+c] = diag2[r-c+n-1] = false;
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        diag1.assign(2*n-1, false); // for / diagonal
        // r + c = constant here 
        // it goes from 0...2n-2 from (0,0) -> (n-1, n-1)
        diag2.assign(2*n-1, false); // for \ diagonal
        // r - c changes by 1 from (n-1, 0) -> (0, n-1)
        // it goes from -(n-1) -> (n-1)
        // we can represent like r - c + (n-1) so that it goes like 0...2n-2
        col.assign(n, false);
        // it goes from 0 -> (n-1)

        // Initialize the board
        vector<string> board(n, string(n, '.'));
        
        backtrack(0, n, board);
        return ans;
    }
};

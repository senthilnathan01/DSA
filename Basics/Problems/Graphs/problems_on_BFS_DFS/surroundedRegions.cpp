#include<iostream>
#include<vector>

using namespace std;
/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.
*/

class Solution 
{
    public:
    void DFS(vector<vector<char>>& board, int i, int j, int rows, int cols) {
        if(i<0 or j<0 or i>=rows or j>=cols or board[i][j] != 'O') return;
        // In DFS convert all 'O' to '#' 
        board[i][j] = '#';
        DFS(board, i-1, j, rows, cols);
        DFS(board, i+1, j, rows, cols);
        DFS(board, i, j-1, rows, cols);
        DFS(board, i, j+1, rows, cols);
    }

    void solve(vector<vector<char>>& board) {
        //We will use boundary DFS to solve this problem
        int rows = board.size();
        if(rows == 0) return;  
        
        int cols = board[0].size();

        // Move over the boundary of board, and find O's
        // Every time we find an O, perform DFS from it's position

        // Moving over first and last column   
        for(int i=0; i<rows; i++) {
            if(board[i][0] == 'O') DFS(board, i, 0, rows, cols);
            if(board[i][cols-1] == 'O') DFS(board, i, cols-1, rows, cols);
        }

        //Moving over first and last row   
        for(int j=0; j<cols; j++) {
            if(board[0][j] == 'O') DFS(board, 0, j, rows, cols);
            if(board[rows-1][j] == 'O') DFS(board, rows-1, j, rows, cols);
        }
        
        // After all DFSs have been performed, board contains three elements,#,O and X
        // 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
        // '#' are elements which cannot be flipped to 'X', so flip them back to 'O'
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }   
    }
};

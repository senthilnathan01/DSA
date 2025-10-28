/*
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

LINK: https://leetcode.com/problems/battleships-in-a-board/description/
*/

class Solution {
public:
    void dfs(int r, int c, int m, int n, vector<vector<char>> &board){
        if(r>=m || c >= n || board[r][c]=='.') return;
        board[r][c]='.';
        dfs(r+1, c, m, n, board);
        dfs(r, c+1, m, n, board);
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j]=='X'){
                    ans++;
                    dfs(i, j, m, n, board);
                }
            }
        }
        return ans;
    }
};

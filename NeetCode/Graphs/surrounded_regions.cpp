/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. 
You do not need to return anything.

LINK: https://leetcode.com/problems/surrounded-regions/description/
*/

class Solution {
public:
    vector<vector<int>> boardCopy;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0,1}, {0, -1}};
    void dfs(int r, int c, int m, int n, vector<vector<char>> &board){
        boardCopy[r][c] = 1;
        for(auto [dr, dc]: dirs){
            int nr = r + dr, nc = c + dc;
            if(0>nr || nr >= m || 0>nc || nc >=n) continue;
            if(board[nr][nc]=='X' || boardCopy[nr][nc]==1) continue;
            dfs(nr, nc, m, n, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        boardCopy.assign(m, vector<int>(n, -1));
        for(int i = 0; i < m; i++){
            if(board[i][0]=='O') dfs(i, 0, m, n, board);
            if(board[i][n-1]=='O') dfs(i, n-1, m, n, board);
        }
        for(int j = 0; j < n; j++){
            if(board[0][j]=='O') dfs(0, j, m, n, board);
            if(board[m-1][j]=='O') dfs(m-1, j, m, n, board);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j]=='O' && boardCopy[i][j]==-1) board[i][j] = 'X'; 
            }
        }
    }
};

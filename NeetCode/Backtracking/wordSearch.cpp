/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are 
horizontally or vertically neighboring. The same letter cell may not be used more than once.

LINK: https://leetcode.com/problems/word-search/description/
*/

class Solution {
public:
    vector<vector<bool>> seen;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    bool dfs(int idx, int r, int c, int n, int m, vector<vector<char>> &board, string word){
        if(idx == word.size()) return true;

        if(0>r || r >=n || 0>c || c>=m || seen[r][c] || board[r][c]!=word[idx]) return false;

        seen[r][c] = true;
        for(int dir = 0; dir < 4; dir++){
            int nr = r + dr[dir], nc = c + dc[dir];
            if(dfs(idx +1, nr, nc, n, m, board, word)) return true;
        }   
        seen[r][c] = false; //backtrack
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        seen.assign(n, vector<bool>(m, false));
        for(int r = 0; r < n; r++){
            for(int c =0; c < m; c++){
                if(dfs(0, r, c, n, m, board, word)) return true;
            }
        }
        return false;
    }

};

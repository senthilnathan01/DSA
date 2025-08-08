/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.

LeetCode Link: https://leetcode.com/problems/word-search/description/
*/

// Approach 1:
// Got TLE with this
// Pasted the refined solution below the first solution

class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    // {down, up, left, right}

    bool isValid(int r, int c, int r_limit, int c_limit, set<pair<int, int>> seen)
    {
        return (0<=r && r< r_limit && 0 <= c && c < c_limit && seen.count({r, c})==0);
    }

    bool exist(int idx, int n, pair<int, int> current_pos, set<pair<int, int>> seen, vector<vector<char>> &board, string &word)
    {
        if(idx == n)
        {
            return true;
        }

        if(idx == 0)
        {
            // Get the first char
            for(int r = 0; r < board.size(); r++)
            {
                for(int c = 0; c < board[0].size(); c++)
                {
                    if(board[r][c]==word[0])
                    {
                        seen.insert({r, c});
                        if(exist(1, n, {r,c}, seen, board, word)) return true;
                        seen.erase({r, c});
                    }
                }
            }
        }
        else
        {
            int curr_r = current_pos.first, curr_c = current_pos.second;
            // Check all four directions except the prev_pos
            for(int i = 0; i < 4; i++)
            {
                int new_r = curr_r + dr[i], new_c = curr_c + dc[i];
                if(isValid(new_r, new_c, board.size(), board[0].size(), seen))
                {
                    if(board[new_r][new_c] == word[idx])
                    {
                        seen.insert({new_r, new_c});
                        if(exist(idx + 1, n, {new_r, new_c}, seen, board, word)) return true;
                        seen.erase({new_r, new_c});
                    }
                }
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = word.size();
        set<pair<int, int>> seen;
        return exist(0, n, {-1, -1}, seen, board, word);
    }
};

// Damn, did some optimization here:
// Changed set<pair<int, int>> seen to vector<vector<bool>> seen
// This eliminates the need for hashlookup
// Also, changed passing by value to passing by reference in some places

// Here is the final solution
class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    // {down, up, left, right}

    bool isValid(int r, int c, int r_limit, int c_limit, vector<vector<bool>> &seen)
    {
        return (0<=r && r< r_limit && 0 <= c && c < c_limit && seen[r][c]==false);
    }

    bool exist(int idx, int n, pair<int, int> current_pos, vector<vector<bool>> &seen, vector<vector<char>> &board, string &word)
    {
        if(idx == n)
        {
            return true;
        }

        if(idx == 0)
        {
            // Get the first char
            for(int r = 0; r < board.size(); r++)
            {
                for(int c = 0; c < board[0].size(); c++)
                {
                    if(board[r][c]==word[0])
                    {
                        seen[r][c] = true;
                        if(exist(1, n, {r,c}, seen, board, word)) return true;
                        seen[r][c] = false;
                    }
                }
            }
        }
        else
        {
            int curr_r = current_pos.first, curr_c = current_pos.second;
            // Check all four directions except the prev_pos
            for(int i = 0; i < 4; i++)
            {
                int new_r = curr_r + dr[i], new_c = curr_c + dc[i];
                if(isValid(new_r, new_c, board.size(), board[0].size(), seen))
                {
                    if(board[new_r][new_c] == word[idx])
                    {
                        seen[new_r][new_c] = true;
                        if(exist(idx + 1, n, {new_r, new_c}, seen, board, word)) return true;
                        seen[new_r][new_c] = false;
                    }
                }
            }
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = word.size();
        vector<vector<bool>> seen(board.size(), vector<bool>(board[0].size(), false));
        return exist(0, n, {-1, -1}, seen, board, word);
    }
};

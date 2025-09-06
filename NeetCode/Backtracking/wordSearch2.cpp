/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells 
are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

LINK: https://leetcode.com/problems/word-search-ii/description/
*/

// BUT THIS GIVES TLE
// THE SOLUTION FOLLOWING IS OPTIMIZED. IT USES TRIE
class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    vector<vector<bool>> seen;
    bool dfs(int idx, int r, int c, int n, int m, vector<vector<char>> &board, string &word){
        if(idx == word.size()) return true;

        for(int dir = 0; dir < 4; dir++){
            int nr = r + dr[dir], nc = c + dc[dir];
            if(nr < 0 || nr >=n || nc <0 || nc >= m || seen[nr][nc] || board[nr][nc]!=word[idx])continue;
            seen[nr][nc] = true;
            if(dfs(idx +1, nr, nc, n, m, board, word)) return true;
            seen[nr][nc] = false;
        }
        return false;
    }

    bool findWord(vector<vector<char>>& board, string &word){
        int n = board.size(), m = board[0].size();
        seen.assign(n, vector<bool>(m, false));

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(board[r][c]==word[0]){
                    seen[r][c] = true;
                    if(dfs(1, r, c, n, m, board, word)) return true;
                    seen[r][c] = false;
                }
            }
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for(string word: words){
            if(findWord(board, word)) ans.push_back(word);
        }
        return ans;
    }
};

// TRIE BASED
class Solution {
public:
    struct TrieNode{
        TrieNode* children[26];
        string word;
        TrieNode(){
            for(int i = 0; i < 26; i++) children[i]=nullptr;
            word = "";
        }
    };

    void insert(TrieNode* root, string &word){
        TrieNode* curr = root;
        for(char c: word){
            if(!curr->children[c-'a']) curr->children[c-'a'] = new TrieNode();
            curr = curr->children[c-'a'];
        }
        curr->word = word;
    }

    vector<string> ans;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>> &board, int r, int c, TrieNode* node){
        char ch = board[r][c];
        if(ch=='#' || !node->children[ch-'a']) return; // cell already visited or no matching path
        node = node->children[ch-'a'];

        // Found a word
        if(!node->word.empty()){
            ans.push_back(node->word);
            node->word = ""; // to avoid duplicates
        }

        board[r][c] = '#'; // mark visited
        for(int dir = 0; dir < 4; dir++){
            int nr = r + dr[dir], nc = c + dc[dir];
            if(nr < 0 || nr >=board.size() || nc < 0 || nc >= board[0].size()) continue;
            dfs(board, nr, nc, node);
        }
        board[r][c] = ch; //backtrack
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // Build a trie
        TrieNode* root = new TrieNode();
        for(string word: words) insert(root, word);

        // DFS from every cell
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                dfs(board, r, c, root);
            }
        }

        return ans;
    }
};

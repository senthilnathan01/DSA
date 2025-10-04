/*
A new alien language uses the English alphabet, but the order of letters is unknown. 
You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. 
If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. 
If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. 
If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. 
  It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

LINK: https://www.geeksforgeeks.org/problems/alien-dictionary/1
*/

class Solution {
  public:
    string findOrder(vector<string> &words) {
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        vector<bool> exists(26, false);
        
        for(const string &word: words){
            for(char ch: word) exists[ch-'a'] = true;
        }
        
        for(int i = 0; i+1< words.size(); i++){
            const string &w1 = words[i];
            const string &w2 = words[i+1];
            int len = min(w1.length(), w2.length());
            int j = 0;
            
            while(j<len && w1[j]==w2[j]) j++;
            
            if(j < len){
                int u = w1[j]-'a';
                int v = w2[j]-'a';
                adj[u].push_back(v);
                indegree[v]++;
            }
            else if(w1.size()>w2.size()) return "";
        }
        
        queue<int> q;
        for(int i = 0; i < 26; i++){
            if(exists[i] && indegree[i]==0) q.push(i);
        }
        
        string res;
        while(!q.empty()){
            int u = q.front(); q.pop();
            res += (char)(u + 'a');
            
            for(int v: adj[u]){
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        
        for(int i = 0; i < 26; i++){
            if(exists[i] && indegree[i]!=0) return "";
        }
        
        return res;
    }
};

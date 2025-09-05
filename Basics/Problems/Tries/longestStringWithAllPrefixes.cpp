/*
Given a string array nums of length n. A string is called a complete string if every prefix of this 
string is also present in the array nums. Find the longest complete string in the array nums.

If there are multiple strings with the same length, return the lexicographically smallest one and 
if no string exists, return "None" (without quotes).
*/

struct TrieNode{
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++) children[i] = nullptr;
    }


};

class Trie{
private:
    TrieNode* root;

public: 
    Trie(){root = new TrieNode();}

    void insert(string &word){
        TrieNode* curr = root;
        for(char c: word){
            if(!curr->children[c-'a']) curr->children[c-'a'] = new TrieNode();
            curr = curr->children[c-'a'];
        }
        curr->isEnd = true;
    }

    bool allPrefixesExist(string &word){
        TrieNode* curr = root;
        for(char c: word){
            if(!curr->children[c-'a']) return false;
            curr = curr->children[c-'a'];
            if(!curr->isEnd) return false;
        }
        return true;
    }

};

class Solution {
public:
    string completeString(vector<string>& nums) {
        Trie trie;
        for(string num: nums) trie.insert(num);

        string ans = "";
        for(auto &w: nums){
            if(trie.allPrefixesExist(w)){
                if(w.size()>ans.size() || (w.size()==ans.size() && w < ans)) ans = w;
            }
        }
        return ans.empty() ? "None":ans;   
    }
};

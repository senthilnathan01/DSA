/*
Given a string s, determine the number of distinct substrings (including the empty substring) of the given string.

A string B is a substring of a string A if B can be obtained by deleting several characters (possibly none) from the 
start of A and several characters (possibly none) from the end of A. Two strings X and Y are considered different if 
there is at least one index i such that the character of X at index i is different from the character of Y at index i (X[i] != Y[i]).
*/

struct TrieNode{
    TrieNode* children[26];

    TrieNode(){for(int i = 0; i < 26; i++) children[i]=nullptr;}
};

class Solution{	
	public:
		int countDistinctSubstring(string s){
			TrieNode *root = new TrieNode();

            int cnt = 0;
            for(int i = 0; i < s.size(); i++){
                TrieNode *curr = root;
                for(int j = i; j < s.size(); j++){
                    char c = s[j];
                    if(!curr->children[c-'a']){
                        curr->children[c-'a'] = new TrieNode();
                        cnt++;
                    }
                    curr = curr->children[c-'a'];
                }
            }

            return cnt + 1;
		}
};

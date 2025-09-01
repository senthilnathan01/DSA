/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA 
without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, 
word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.

Link: https://leetcode.com/problems/longest-string-chain/description/
*/

// TC = O(N^2 *L)
class Solution {
public:
    bool compare(string big, string small){
        if(big.size()!= small.size()+1) return false;

        int ptr1 = 0, ptr2 = 0;
        int n = big.size();
        while(ptr1 <n){
            if(ptr2 < small.size() && big[ptr1]==small[ptr2]){
                ptr1++;
                ptr2++;
            }
            else ptr1++;
        }
        return ptr2 == small.size();
    }
    int longestStrChain(vector<string>& words) {
        vector<string> temp = words;
        sort(temp.begin(), temp.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        int n = temp.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 0 ; i< n; i++){
            for(int j = 0; j < i; j++){
                if(compare(temp[i], temp[j]) && dp[i]<1 + dp[j]) dp[i] = 1 + dp[j];
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};

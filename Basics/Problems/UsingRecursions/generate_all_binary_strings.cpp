/*
Given an integer N , Print all binary strings of size N which do not contain consecutive 1s.

A binary string is that string which contains only 0 and 1.

GFG Link: https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1
*/

class Solution {
  public:
    void backtrack(int n, int num, string word, vector<string> &ans)
    {
        if(n==num)
        {
            ans.push_back(word);
            return;
        }
        
        for(int i = 0; i < 2; i++)
        {
            if(i==1 && word.back()=='1') continue;
            
            word.push_back(i + '0');
            backtrack(n + 1, num, word, ans);
            word.pop_back();
        }
    }
    
    vector<string> generateBinaryStrings(int num) {
        vector<string> ans;
        string word;
        backtrack(0, num, word, ans);
        return ans;
    }
};

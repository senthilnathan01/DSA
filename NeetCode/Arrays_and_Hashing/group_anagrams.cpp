/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

Leetcode Link: https://leetcode.com/problems/group-anagrams/description/
*/

// Solution 1:
class Solution {
private: 
    vector<int> getsignature(string s)
    {
        vector<int> arr(26, 0);
        for(auto c: s) arr[c-'a']++;
        return arr;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int> , int> signature2group;
        vector<vector<string>> ans;
        for(auto s: strs)
        {
            vector<int> signature = getsignature(s);
            if(signature2group.find(signature)!=signature2group.end())
            {
                ans[signature2group[signature]].push_back(s);
            }
            else
            {
                signature2group[signature] = ans.size();
                ans.push_back({s});
            }
        }
        return ans;
    }
};

// Solution 2:
// Realised how suboptimal the previous solution was!
// Here we just sort the strings and easily get the anagram groups
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;
        for(string s: strs)
        {
            string word = s;
            sort(word.begin(), word.end());
            mpp[word].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto p: mpp) ans.push_back(p.second);

        return ans;
    }
};

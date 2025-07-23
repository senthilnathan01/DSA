/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Anagram: An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, using all the original letters exactly once.

Leetcode Link: https://leetcode.com/problems/valid-anagram/description/
*/

// Solution 1:
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char, int> count_s, count_t;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            count_s[s[i]]++;
            count_t[t[i]]++;
        }

        if(count_s.size()!=count_t.size()) return false;
        for(auto p: count_s)
        {
            if(count_t[p.first]!=p.second) return false;
        }
        return true;
    }
};

// Solution 2:
// Much faster
// Takes unnnecessary space tho
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> cnt(26, 0);
        int n = s.size();
        for(int i = 0; i < n; i++) cnt[s[i]-'a']++;
        for(int i = 0; i < n; i++) cnt[t[i]-'a']--;
        for(int i = 0; i < 26; i++) if(cnt[i]!=0) return false;
        return true;
    }
};

// Solution 3: 
// More optimised version of Solution 2 by using better data types and 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<uint16_t> cnt(26, 0);
        uint16_t n = s.size();
        uint16_t i = 0;
        for(; i < n; i++)
        {
            cnt[unsigned(s[i]-'a')]++;
            cnt[unsigned(t[i]-'a')]--;
        }
        for(i = 0; i < 26; i++) if(cnt[i]!=0) return false;
        return true;
    }
};


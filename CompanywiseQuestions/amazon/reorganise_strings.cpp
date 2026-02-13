/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

LINK: https://leetcode.com/problems/reorganize-string/description/?envType=problem-list-v2&envId=7p5x763
*/

class Solution {
public:
    string reorganizeString(string s) {
        // few observations:
        // 1.max freq of char <= (n+1)/2 else return ""
        // 2.place max freq char at first (strategy)
        // 3.instead of placing most freq char at a time, place two most freq char at a time (strategy)
        // that way we avoid adjacency and make the process faster too
        // 4.this leads us one of the two cases at the end - 2 remaining chars or 1 remaining char
        
        int n = s.size();
        unordered_map<char, int> mp;
        for(char c: s) mp[c]++;

        // check for possibility of arrangement
        int maxi = 0;
        for(auto &p: mp) maxi = max(maxi, p.second);
        if(maxi>(n+1)/2) return "";

        // {freq, char}
        priority_queue<pair<int, char>> pq;
        for(auto &p: mp) pq.push({p.second, p.first});

        string ans = "";
        while(pq.size()>1){
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();
            ans += c1;
            ans += c2;

            if(--f1>0)pq.push({f1, c1});
            if(--f2>0)pq.push({f2,c2});
        }
        if(!pq.empty()){
            if(pq.top().first>1) return "";
            ans += pq.top().second;
        }
        return ans;
    }
};

// Optimised version:

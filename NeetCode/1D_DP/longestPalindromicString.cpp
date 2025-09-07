/*
Given a string s, return the longest palindromic substring in s.

LINK: https://leetcode.com/problems/longest-palindromic-substring/
*/

// So many approaches for this question
// Approach 1
// Brute Force O(n^2*n) = O(n^3)
// Check all n^2 substrings for palindrome and get the max length of all


// Approach 2 O(N^2)
// Set the mid point ->expand from mid point -> check for palindrome -> get max length of all
// don't forget, number of mid points = 2*n -1

// Approach 3
// 1D DP

// Approach 4
// A recursion approach
// TC is bad O(N^3)
// But an interesting solution anyways

// Approach 1 CODE
class Solution {
private: 
    bool isPalindrome(string &s, int i, int j){
        int l = i, r = j;
        while(l<r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        string maxi = "";
        for(int i = 0; i< n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrome(s, i, j)){
                    if(maxi.length()<j-i+1) maxi = s.substr(i, j-i+1);
                }
            }
        }
        return maxi;
    }
};

// Approach 2 CODE
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1) return s;

        auto expand = [&](int l, int r){
            while(l >= 0 && r < s.length() && s[l]==s[r]){
                l--;
                r++;
            }
            return s.substr(l+1, r-l-1);
        };

        string maxStr = s.substr(0, 1);
        for(int i = 0; i < s.length()-1; i++){
            string odd = expand(i, i);
            string even = expand(i, i+1);

            if(odd.length()>maxStr.length()) maxStr = odd;
            if(even.length()>maxStr.length()) maxStr = even;
        }
        return maxStr;
    }
};

// Approach 3
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==1) return s;

        int maxLen = 1;
        string maxStr = s.substr(0, 1);
        s = "#" + regex_replace(s, regex(""), "#") + "#";

        // palindrome radius at position i
        vector<int> dp(s.length(), 0);
        int center = 0;
        int right = 0;

        for(int i = 0; i < s.length(); i++){
            // reusing knowledge
            // If i is inside the current palindrome
            if(i<right) dp[i] = min(right-i, dp[2*center-i]);

            // Expand if possible
            while(i-dp[i]-1 >=0 
            && i + dp[i] + 1 < s.length() 
            && s[i-dp[i]-1]==s[i+dp[i]+1]) dp[i]++;

            // set the center and right to its appropriate values
            // If the new palindrome expands further than current right
            if(i+dp[i] > right){
                center = i;
                right = i + dp[i];
            }

            // Update the ans
            if(dp[i] > maxLen){
                maxLen = dp[i];
                maxStr = s.substr(i-dp[i], 2*dp[i]+1);
                maxStr.erase(remove(maxStr.begin(), maxStr.end(), '#'), maxStr.end());
            }
        }
        return maxStr;
    }
};

// Approach 4 CODE
class Solution {
public:
    string longestPalindrome(string s) {
        if(s==string(s.rbegin(), s.rend())) return s;

        string l = longestPalindrome(s.substr(1));
        string r = longestPalindrome(s.substr(0, s.size()-1));

        if(l.length() > r.length()) return l;
        else return r;
    }
};

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

LC Link: https://leetcode.com/problems/valid-palindrome/description/
*/

// Solution 1:
// Good TC but bad SC
// Gotta use two pointers. Check out the next solution
class Solution {
public:
    bool isPalindrome(string s) {
        // create another string with just lower case letters
        string s_mod;
        for(char c: s)
        {
            if(isalpha(c)) s_mod += static_cast<char>(tolower(c));
            else if(isdigit(c)) s_mod += c;
        }

        string s_reverse = s_mod;
        reverse(s_reverse.begin(), s_reverse.end());
        if(s_reverse == s_mod) return true;
        return false;
    }
};

// Solution 2:
// Solution using two pointers
class Solution {
public:
    bool isPalindrome(string s) {
        // Use Two pointers 
        // Avoid creating another reversed string
        int n = s.length();
        int p1 = 0;
        int p2 = n - 1;
        while(p1<=p2)
        {
            // Skip through the nonsense
            while(p1 < p2 && !isalnum(s[p1])) p1++;
            while(p2 > p1 && !isalnum(s[p2])) p2--;

            if(tolower(s[p1]) != tolower(s[p2])) return false;
            p1++;
            p2--;

        }
        return true;
    }
};

// Remember isalpha() && isdigit() is done by isalnum() 
// Cool right?

#include<iostream>
#include<unordered_map>

using namespace std;

/*
    Problem:
Given a string s, find the length of the longest  substring without repeating characters.

*/

// Brute Force Method
// TC = O(N^2)
// Generate all such substrings and get the max length
int longestSubstring1(string& s)
{
    int maxLength = 0;
    for(int i = 0; i<s.size(); i++)
    {
        int length = 0;
        unordered_map <int, int> mpp;
        string sub = "";
        for(int j = i; j<s.size(); j++)
        {
            if(mpp[s[j]]!=0) break;
            else
            {
                mpp[s[j]]++;
                sub += s[j];
            }
        }
        length = sub.size();
        maxLength = max(length, maxLength);
    }
    return maxLength;
}

// Optimal Approach
// TC = O(N)
// SC = O(256)
int longestSubstring2(string& s)
{
    // Initialize the map
    unordered_map<int, int> mpp;
    for(int i = 1; i<=256; i++)
    {
        mpp[i]=-1;
    }
    int l = 0, r = 0, maxLength = 0;
    int n = s.size();
    while(r<n)
    {
        if(mpp[s[r]]!=-1)
        {
            if(mpp[s[r]]>=l)
            {
                l = mpp[s[r]]+1;
            }
        }
        int length = r-l+1;
        maxLength = max(length, maxLength);
        mpp[s[r]]=r;
        r++;
    }

    return maxLength;
}

int main()
{
    string s = "abcabcbb";
    cout<<longestSubstring1(s)<<endl;
    cout<<longestSubstring2(s);
}

// OUTPUT:
// 3
// 3

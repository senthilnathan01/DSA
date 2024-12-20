#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
Problem:
You are given a string s and an integer k. 
You can choose any character of the string and change it to any other uppercase English character. 
You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/

// Brute Force Approach
// Get all the relevant substrings and get the max possible length
// Length of the substring - maxFreq <=k
// TC = O(N^2)
int characterReplacement1(string& s, int k)
{
    int n = s.size();
    int maxLen = 0;
    for(int i = 0; i<n; i++)
    {
        unordered_map<int, int> mpp;
        int maxFreq = 0;
        for(int j = i; j< n; j++)
        {
            mpp[s[j]]++;
            maxFreq = max(maxFreq, mpp[s[j]]);
            int noOfChange = (j-i+1) - maxFreq;
            if(noOfChange <= k)
            {
                maxLen = max(j-i+1, maxLen);
            }
            else break;
        }
    }
    return maxLen;
}

// TC = O(N)
int characterReplacement2(string& s, int k)
{
    int l = 0, r = 0, n = s.size(), maxFreq = 0, maxLen = 0;
    unordered_map<char, int> mpp;
    while(r<n)
    {
        mpp[s[r]]++;
        maxFreq = max(maxFreq, mpp[s[r]]);
        while((r-l+1 - maxFreq) > k)
        {
            mpp[s[l]]--;
            maxFreq = 0;
            for(auto p: mpp)
            {
                maxFreq = max(maxFreq, p.second);
            }
            l++;
        }
        if((r-l+1 - maxFreq)<=k)
        {
            maxLen = max(maxLen, r - l +1);
        }
        r++;
    }
    return maxLen;
}

int main()
{
    string s = "AABABBA";
    int k = 1;
    cout<<characterReplacement1(s, k)<<endl;
    cout<<characterReplacement2(s, k);
}

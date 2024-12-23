#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

/*
Problem:
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
*/
// Brute Force Approach
// TC = O(N^2)
// SC = O(1)
int numberOfSubstrings(string s) {
    int n = s.length(), cnt = 0;
    unordered_map<char, int> mpp = {{'a', 0}, {'b', 0}, {'c', 0}};
    for(size_t i = 0; i< n; i++)
    {
        for (auto& pair : mpp) pair.second = 0;
        for(size_t j = i; j < n; j++)
        {
            mpp[s[j]] = 1;
            if(mpp['a']+mpp['b']+mpp['c'] == 3) cnt++;
        }
    }
    return cnt;
}

// Better Approach
// TC = O(N^2) but with better time complexity
// SC = O(1)
int numberOfSubstrings2(string s) {
    int n = s.length(), cnt = 0;
    unordered_map<char, int> mpp = {{'a', 0}, {'b', 0}, {'c', 0}};
    for(size_t i = 0; i< n; i++)
    {
        for (auto& pair : mpp) pair.second = 0;
        for(size_t j = i; j < n; j++)
        {
            mpp[s[j]] = 1;
            if(mpp['a']+mpp['b']+mpp['c'] == 3){
                cnt+=(n-j);
                break;
            }
        }
    }
    return cnt;
}

// Optimal Approach using two pointers
// TC = O(N)
int numberOfSubstrings3(string s)
{
    vector<int> lastSeen = {-1,-1,-1};
    int cnt = 0, n = s.length();
    for(size_t i = 0; i< n; i++)
    {
        lastSeen[s[i]-'a'] = i;
        cnt += (1+ *min_element(lastSeen.begin(), lastSeen.end()));

    }
    return cnt;
}


int main()
{
    string s = "abcabc";
    cout<<numberOfSubstrings(s)<<endl;
    cout<<numberOfSubstrings2(s)<<endl;
    cout<<numberOfSubstrings3(s)<<endl;
}

// OUTPUT:
// 10
// 10
// 10
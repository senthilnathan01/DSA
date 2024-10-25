#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Given a string s, sort it in decreasing order based on the frequency of the characters. 
The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.
*/

string frequencySort(string s) {
    // Count the frequency of each character.
    unordered_map<char, int> freq;
    for(char c : s) freq[c]++;

    // Create a vector of pairs {frequency, character} to sort by frequency.
    vector<pair<int, char>> pairs;

    for(auto& p : freq)
    {
        pairs.push_back({p.second, p.first});
    }

    // Sort the pairs in descending order of frequency.
    sort(pairs.begin(), pairs.end(), greater<pair<int, char>>());

    // Construct the sorted string.
    string result;

    for (auto& p : pairs) 
    {
        for (int i = 0; i < p.first; ++i) result += p.second;
    }

    return result;
}


int main()
{
    string s = "naavit";
    cout<<frequencySort(s)<<endl;
}

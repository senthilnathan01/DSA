#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<algorithm>

using namespace std;

void sortmymap(vector<pair<string, int>>& ans)
{
    sort(ans.begin(), ans.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first; // Lexicographical comparison
        } else {
            return a.second > b.second; // Comparison by integer value
        }
    });
    for (auto& it : ans) {
        cout << it.first << "\n";
    }
}

void generateSubsequences(string str, string curr, int index, map<string, vector<int>>& subsequences, vector<int>& currentIndices) {
    if (index == str.length()) {
        if (curr.length() > 0) {
            subsequences[curr] = currentIndices;
        }
        return;
    }

    // Include the current character
    currentIndices.push_back(index);
    generateSubsequences(str, curr + str[index], index + 1, subsequences, currentIndices);
    currentIndices.pop_back();

    // Exclude the current character
    generateSubsequences(str, curr, index + 1, subsequences, currentIndices);
}

void solve()
{
    string s = "ABCDE";
    vector<int> values(5);
    for(int i = 0; i<5; i++) cin>>values[i];
    map<string, vector<int>> subsequences;
    vector<int> currentIndices;
    vector<pair<string, int>> ans;
    generateSubsequences(s, "", 0, subsequences, currentIndices);
    
    for (auto& pair : subsequences) {
        int value = 0;
        for (int index : pair.second) {
            value += values[index];
        }
        ans.push_back(make_pair(pair.first, value));
    }

    sortmymap(ans);
}

int main()
{
    solve();
}
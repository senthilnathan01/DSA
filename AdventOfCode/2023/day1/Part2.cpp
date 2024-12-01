#include<iostream>
#include<unordered_map>
#define CODE ios::sync_with_stdio(false); cin.tie(0);
#include<vector>
#include<algorithm>

using namespace std;

vector<int> replaceWordsWithNumbers(string& text, unordered_map<string, char> wordToNumber)
{
    // For a given word obtain the occurence of numbers[both in numerical and word format]
    // store in a vector -> sort the vector -> get the first number and last number
    vector<pair<int, int>> NumberPositions;

    // Check for word format numbers (all occurences)
    for(auto pair: wordToNumber)
    {
        int it = text.find(pair.first);
        while (it != -1) {
            NumberPositions.push_back({int(pair.second - '0'), it});
            it = text.find(pair.first, it+1);
        }
    }
    // Check for numerical format numbers (all occurences)
    for(int i = 0; i<=9; i++)
    {
        int it = text.find(i+48);
        while (it != -1) {
            NumberPositions.push_back({i, it});
            it = text.find(i+48, it+1);
        }
    }

    sort(NumberPositions.begin(), NumberPositions.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    vector<int> ans;
    ans.push_back(NumberPositions[0].first);
    ans.push_back(NumberPositions[NumberPositions.size()-1].first);

    return ans;
}


void solve(int& sum)
{
    int testCases = 1000;
    unordered_map <string, char> wordToNumber = 
    {
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'}
    };

    while(testCases--)
    {
        string text;
        cin>>text;

        vector<int> ans = replaceWordsWithNumbers(text, wordToNumber);
        sum += (ans[0]*10 + ans[1]);
    }
}

int main()
{
    CODE
    int sum = 0;
    solve(sum);
    cout<<sum;
}








#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) return ""; // Empty array has no common prefix
    if(strs.size() == 1) return strs[0];

    // Choose the size of the smallest string
    int min_length = strs[0].size();
    for(string str: strs) min_length = min(min_length, int(str.size()));

    // Iterate through characters of the shortest string.
    for (int index = 0; index < min_length; index++) {
        char current_char = strs[0][index];
        for (int j = 1; j < strs.size(); j++) {
            if (strs[j][index] != current_char) {
                return strs[0].substr(0, index); // Return the common prefix up to the current index
            }
        }
    }

    // If all strings have the same prefix up to the end of the shortest string, return that prefix.
    return strs[0].substr(0, min_length);
}

int main()
{
    vector<string> strs = {"flower","flow","flight"};
    cout<<longestCommonPrefix(strs)<<endl;

}
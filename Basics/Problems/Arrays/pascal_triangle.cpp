#include<bits/stdc++.h>
using namespace std;

/*
Given an integer numRows, return the first numRows of Pascal's triangle.
1 <= numRows <= 30
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        int currRow = 1;
        while(currRow < numRows)
        {
            vector<int> prevRow = ans.back();
            vector<int> newRow;
            newRow.push_back(1);
            for(int i = 0; i<prevRow.size()-1; i++)
            {
                newRow.push_back(prevRow[i]+prevRow[i+1]);
            }
            newRow.push_back(1);
            currRow++;
            ans.push_back(newRow);
        }
        return ans;
    }
};
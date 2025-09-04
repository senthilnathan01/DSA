/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

LINK: https://leetcode.com/problems/count-square-submatrices-with-all-ones/description/
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> arr = matrix;
        int ans = accumulate(arr[0].begin(), arr[0].end(), 0);
        for(int i = 1; i < arr.size(); i++) ans += arr[j][0];
        for(int i = 1; i < arr.size(); i++){
            for(int j = 1; j < arr[0].size(); j++){
                if(arr[i][j]==1){
                    arr[i][j] += min(arr[i-1][j], min(arr[i][j-1], arr[i-1][j-1]));
                    ans += arr[i][j];
                }
            }
        }
        return ans;
    }
};

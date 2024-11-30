#include<iostream>
#include<vector>

using namespace std;

/*
Given an m x n matrix, return all elements of the matrix in spiral order.
*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;

    int m = matrix.size();
    int n = matrix[0].size();
    
    int top = 0, left = 0, bottom = m - 1, right = n - 1;

    while(top<bottom && left<right)
    {
        for(int current_col = left; current_col<=right -1; current_col++) ans.push_back(matrix[top][current_col]);
        for(int current_row = top; current_row<=bottom -1; current_row++) ans.push_back(matrix[current_row][right]);
        for(int current_col = right; current_col>= left +1; current_col--) ans.push_back(matrix[bottom][current_col]);
        for(int current_row = bottom; current_row>= top +1; current_row--) ans.push_back(matrix[current_row][left]);
        top++;
        right--;
        bottom--;
        left++;
    }

    // Some leftovers
    if(top == bottom && left != right) for(int current_col = left; current_col<=right; current_col++) ans.push_back(matrix[top][current_col]);
    else if(left == right && top != bottom) for(int current_row = top; current_row <= bottom; current_row++) ans.push_back(matrix[current_row][left]);
    else if(top == bottom && left == right) ans.push_back(matrix[top][left]);

    return ans; 
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> ans = spiralOrder(matrix);
    for(auto num: ans) cout<<num<<" ";
}








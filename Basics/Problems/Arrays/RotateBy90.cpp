#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.
*/

void rotate(vector<vector<int>>& matrix) {
    // Transpose the matrix
    int rows = matrix.size(), columns = matrix[0].size();
    for(int i = 0; i< rows; i++)
    {
        for(int j = i; j < columns; j++) swap(matrix[i][j], matrix[j][i]);
    }

    // Reverse the rows
    for(int i = 0; i<rows; i++) reverse(matrix[i].begin(), matrix[i].end());
}


int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    cout<<"Original Matrix"<<endl;
    for(auto row: matrix)
    {
        for(auto num: row) cout<<num<<" ";
        cout<<endl;
    }
    rotate(matrix);
    cout<<"Rotated Matrix"<<endl;
    for(auto row: matrix)
    {
        for(auto num: row) cout<<num<<" ";
        cout<<endl;
    }
}


// OUTPUT:
// Original Matrix
// 1 2 3 
// 4 5 6 
// 7 8 9 
// Rotated Matrix
// 7 4 1 
// 8 5 2 
// 9 6 3 





#include<iostream>
#include<vector>

using namespace std;

/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

int lower_bound(vector<int> matrix, int target, int n){
    int ans = n-1;
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(matrix[mid]==target) ans = mid;
        else if(matrix[mid]<target){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Find the lower bound row wise and column wise
    // Do the binary search operation in the column or in the row (determined by the which has the maximum lower bound)
    int lower_bound_col_wise = lower_bound(matrix[0], target, matrix[0].size());
    int lower_bound_row_wise = matrix.size() - 1;
    int low = 0;
    int high = matrix.size() - 1;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if(matrix[mid][0]==target) return true;
        else if(matrix[mid][0]<target){
            lower_bound_row_wise = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    
    if(lower_bound_col_wise>lower_bound_row_wise){
        // Do binary search along the column
        int low = 0;
        int high = lower_bound_row_wise;
        while(low<=high){
            int mid = (low+high)/2;
            if(matrix[mid][lower_bound_col_wise]==target) return true;
            else if(matrix[mid][lower_bound_col_wise]<target) low = mid + 1;
            else high = mid - 1;
        }
    }
    else{
        // Do binary search along the row
        int low = 0;
        int high = lower_bound_col_wise;
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(matrix[lower_bound_row_wise][mid] == target) return true;
            else if(matrix[lower_bound_row_wise][mid] < target) low = mid + 1;
            else high = mid - 1;
        }
    }
    
    return false;
}

int main() {
    vector<vector<int>> arr = {
        {0,1,2},
        {4,8,10},
        {15,16,17}
    };
    cout<<searchMatrix(arr, 10)<<endl;
}

// OUTPUT:
// 1


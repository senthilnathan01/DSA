#include<iostream>
#include<vector>

using namespace std;

/*
You are given a 2D array consisting of only 1's and 0's, where each row is sorted in non-decreasing order. 
You need to find and return the index of the first row that has the most number of 1s. 
If no such row exists, return -1.
Note: 0-based indexing is followed.
*/

// Approaches (2):
// Approach 1 - Brute Force- Nested Loops
// Count the number of 1s in each row and return the index of row with maximum count of 1s
// TC = O(n*m)

int rowWithMax1s_1(vector<vector<int> > &arr)
{
    int max_row_count = -1;
    int max_row_index = -1;
    int n = arr.size();
    int m = arr[0].size();
    for(int i = 0; i<n; i++){
        int count_row = 0;
        for(int j = 0; j< m; j++){
            count_row += arr[i][j];
        }
        if(count_row > max_row_count)
        {
            max_row_count = count_row;
            max_row_index = i;
        }
    }
    return max_row_index;
}



// Approach 2 - Optimal - Using binary search
// TC = O(n*logm)
// Note that each row is sorted. Searching for the first occurence of 1 using binary search will give us the row with maximum number of ones.
// How do we get the first occurence of 1

// We can either do "lowerbound(1)" or "upperbound(0)" or "first_occurence(1)" operation which have been discussed in other problems already. 
// Check out these files in the same folder, "Binary_Search"

// Let's do this using lower bound(1)
int lower_bound(vector<int> arr, int n, int x){
    int low = 0, high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid] >= x ){
            ans = mid;
            high = mid - 1; //search in the left part
        } 
        else low = mid + 1; //search in the right part
    }
    return ans;
}

int rowWithMax1s_2(vector<vector<int> > &arr)
{
    int count_max = 0;
    int max_count_index = -1;
    int n = arr.size();
    int m = arr[0].size();
    for(int i=0; i<n; i++){
        int count = m -lower_bound(arr[i], m, 1);
        if(count>count_max){
            count_max = count;
            max_count_index = i;
        } 
    }
    return max_count_index;
}

int main() {
    vector<vector<int>> arr = {
        {0,1,1},
        {1,1,1},
        {0,0,0}
    };
    cout<<rowWithMax1s_1(arr)<<endl;
    cout<<rowWithMax1s_2(arr)<<endl;
}

// OUTPUT:
// 1
// 1

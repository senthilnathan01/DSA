#include<iostream>
#include<vector>

using namespace std;

/*
Given an array arr[], with 0-based indexing, select any two indexes, i and j such that i < j. 
From the subarray arr[i...j], select the smallest and second smallest numbers and add them, you will get the score for that subarray. 
Return the maximum possible score across all the subarrays of array arr[].

2 ≤ arr.size ≤ 10^5
1 ≤ arr[i] ≤ 10^6
*/

// Approach:
// By Observation:
// Such two numbers which gives max sum will always be next to each other

int pairWithMaxSum(vector<int> &arr) {
  
    int n = arr.size();
    int small1 = arr[0];
    int small2 = arr[1];
    int sum = small1 + small2;
    int newSum = sum;
    for(int i = 2; i < n; i++)
    {
        newSum = newSum - small1 + arr[i];
        small1 = small2;
        small2 = arr[i];
        sum = max(newSum, sum);
    }
    return sum;
}

int main()
{
    vector<int> arr = {5, 4, 3, 1, 6};
    cout<<pairWithMaxSum(arr);
}

// OUTPUT:
// 9


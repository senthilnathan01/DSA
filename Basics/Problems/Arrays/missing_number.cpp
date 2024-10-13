#include <iostream>
#include<vector>
using namespace std;

/*
Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.
*/

// Finds the missing number in a sorted array of integers from 0 to n-1.
int find_missing_number(const vector<int>& nums) {
    int n = nums.size();

    // Initialize an auxiliary array of size n+1 with -1.
    vector<int> visited(n + 1, -1);

    // Mark the elements in nums as visited in the auxiliary array.
    for (int num : nums) {
        visited[num] = num;
    }

    // Find the first index in the auxiliary array that is not visited.
    for (int i = 0; i <= n; i++) {
        if (visited[i] == -1) {
            return i;
        }
    }

    // If no missing number is found, return 0.
    return 0;
}

int main() {
    vector<int> nums = {0, 1, 3};

    cout << find_missing_number(nums) << endl;

    return 0;
}

#include<iostream>
#include<vector>

using namespace std;

/*
PROBLEM:
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

int main()
{
    vector<int> nums = {1,2,2,4,1};
    int ans = 0;
    for(int num: nums) ans = ans^num;
    cout<<ans;
}

// OUTPUT:
// 4

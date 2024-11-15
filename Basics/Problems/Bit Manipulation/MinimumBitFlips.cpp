#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
/*
PROBLEM:
Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

// Approach 1: Using Map
// TC = O(N*logM + M) where M = N/2 + 1
// SC = O(M)

int singleNumber1(vector<int> nums)
{
    unordered_map<int, int> counts;
    for(auto num: nums) counts[num]++;
    for(auto it: counts){
        if(it.second==1) return it.first;
    }
    return -1;
}

// Optimal Approach:
// TC = O(N)
// SC = O(1)

int singleNumber2(vector<int> nums)
{
    int ans = 0;
    for(int num: nums) ans = (ans^num);
    return ans;   
}

int main()
{
    vector<int> array = {4,1,2,1,2};
    cout<<singleNumber1(array)<<endl;
    cout<<singleNumber2(array);
}

// OUTPUT:
// 4
// 4





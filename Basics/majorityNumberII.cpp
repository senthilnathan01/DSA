#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
Problem:
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
*/

// Optimal Approach
// TC = O(N)
vector<int> majorityNumbers(vector<int> nums)
{
    int minNum = nums.size()/3 + 1;
    vector<int> ans;
    unordered_map <int, int> mpp;
    for(int i = 0; i<nums.size(); i++)
    {
        mpp[nums[i]]++;
        if(mpp[nums[i]]==minNum) ans.push_back(nums[i]);
        if(ans.size()==2) break;
    }
    return ans;
}


int main()
{
    vector<int> nums = {1,1,1,3,-3,2,2,2};
    vector<int> ans = majorityNumbers(nums);
    for(int num: ans) cout<<num<<" ";
}   

// OUTPUT:
// 1 2 
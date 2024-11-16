#include<iostream>
#include<vector>

using namespace std;

/*
PROBLEM:
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

// TC = O(N*2^N)
// SC -> O(2^N*N)

vector<vector<int>> subsets(vector<int>& nums) 
{
    int size = nums.size();
    int numSubSets = (1<<size);

    vector<vector<int>> powerSet;

    for(int num = 0; num < numSubSets; num++)
    {
        vector<int> subset;
        for(int i = 0; i<size; i++)
        {
            if(num&(1<<i)) subset.push_back(nums[i]);
        }
        powerSet.push_back(subset);
    }
    return powerSet;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);
    for(auto subset: ans) 
    {
        for(auto num:subset) cout<<num<<" ";
        cout<<endl;
    }
    return 0; 
}

// OUTPUT:
/*

1 
2 
1 2 
3 
1 3 
2 3 
1 2 3 
*/


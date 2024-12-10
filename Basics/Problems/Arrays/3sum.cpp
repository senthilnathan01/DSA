#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<set>

using namespace std;

/*
Problem:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

// Brute Force Solution will have TC = O(N^3) by checking all the triplets. 

// Better Solution with TC = O(N^2)
// SC = O(N) for the extra hashset
set<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> ans;
    for(int i =0; i<n; i++)
    {
        unordered_set<int> mySet;
        for(int j=i+1; j<n;j++)
        {
            int third = -(nums[i]+nums[j]);
            if(mySet.find(third)!=mySet.end())
            {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                ans.insert(temp);
            }
            mySet.insert(nums[j]);
        }

    }
    return ans;
}

// Optimal Solution
// Using two pointers
// O(nlogn) - for sorting and O(n^2) - for the loops
// SC = 0 (nothing extra except for the answer)(note: Remember, I only worry about the extra space required to give the answer)
set<vector<int>> threeSumOS(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    set<vector<int>> ans;
    int n = nums.size();
    for(int i =0; i<n; i++)
    {
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k)
        {
            int sum = nums[i]+nums[j]+nums[k];
            if(sum<0)
            {
                j++;
            }
            else if(sum>0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.insert(temp);
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k+1]) k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    set<vector<int>> ans = threeSum(nums);
    for(auto vec: ans)
    {
        for(auto num: vec) cout<<num<<" ";
        cout<<endl;
    }
    set<vector<int>> ans = threeSumOS(nums);
    for(auto vec: ans)
    {
        for(auto num: vec) cout<<num<<" ";
        cout<<endl;
    }
}   


#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;

/*
Problem:
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array of arr[], where arr[i]  is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array of fruits, return the maximum number of fruits you can pick.
*/

/*
Reformulation:
Find the max length of sub array with at most two types of fruits
*/

// Brute Force Approach
// TC = O(N^2)
// Get all the relevant subarrays and get the max length
int totalFruits1(vector<int>& nums)
{
    int maxLen = 0, n = nums.size();
    for(int i = 0; i<n; i++)
    {
        set<int> fruitTypes;
        int len = 0;
        for(int j = i; j < n; j++)
        {
            fruitTypes.insert(nums[j]);
            if(fruitTypes.size()>2) break;
            else
            {
                len++;
                maxLen = max(len, maxLen);
            }
        }
    }
    return maxLen;
}

// Better Approach:
// TC = O(2N) => O(N)
// SC = O(3) => O(1)
int totalFruits2(vector<int>& nums)
{
    int l = 0, r = 0, maxLen = 0, n = nums.size();
    unordered_map<int, int> mpp;
    while(r<n)
    {
        mpp[nums[r]]++;
        if(mpp.size()>2)
        {
            while(mpp.size()>2)
            {
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
        }
        if(mpp.size()<=2)
        {
           maxLen = max(maxLen, r-l+1); 
        }
        r++;
    }   
    return maxLen;
}

// Best Approach:
// TC = O(N)
// SC = O(3) => O(1)
int totalFruits3(vector<int>& nums)
{
    int l = 0, r = 0, maxLen = 0, n = nums.size();
    unordered_map<int, int> mpp;
    while(r<n)
    {
        mpp[nums[r]]++;
        if(mpp.size()>2)
        {
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0) mpp.erase(nums[l]);
            l++;
        }
        if(mpp.size()<=2)   maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {3, 1, 2, 2, 2, 2};
    cout<<totalFruits1(nums)<<endl;
    cout<<totalFruits2(nums)<<endl;
    cout<<totalFruits3(nums)<<endl;
}

// OUTPUT:
// 5
// 5
// 5
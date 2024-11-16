#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
PROBLEM:
Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. 
Find the two numbers in decreasing order which has odd occurrences.*/

// Approach 1: (Optimal)
// Using bitwise operations and buckets

// TC 
// SC

pair<int, int> singleNumber(vector<int> nums)
{
    long XOR = 0;
    for(int num: nums) XOR ^= num;

    // Get the rightmost setbit
    int rightMostBit = (XOR&(XOR-1))^XOR;

    int b1 = 0, b2 = 0;
    for(int num: nums)
    {
        if(num&rightMostBit) b1 ^=num;
        else b2 ^= num;
    }

    return {b1, b2};
}

int main()
{
    vector<int> nums = {5,5,6,3,4,4};
    pair<int, int> ans = singleNumber(nums);
    cout<<ans.first<<" "<<ans.second<<endl; 

}

// OUTPUT:
// 3 6

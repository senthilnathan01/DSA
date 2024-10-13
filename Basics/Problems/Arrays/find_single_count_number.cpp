#include <iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

/*
Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.
*/

// 2 Approaches:

// 1.Using Maps
// TC = O(N)
// SC = O(N)

// Finds the single number that appears once in a given array.
int singleNumber1(const vector<int>& nums) {
    unordered_map<int, int> counts;
    for (int num : nums) {
        counts[num]++;
    }
    for (const auto& entry : counts) {
        if (entry.second == 1) {
            return entry.first;
        }
    }
    return -1;
}

// 2.Sorting
// TC = O(nlogn)
// SC = O(1)

int singleNumber2(vector<int>& nums){
    // include <algorithm> header to use sort STL
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=0; i<n; i+=2){
        if(nums[i]!=nums[i+1]) return nums[i];
    }
    return nums[n-1];
}

int main() {
    vector<int> nums = {1,2,1};
    cout<<singleNumber1(nums)<<endl;
    cout<<singleNumber2(nums)<<endl;
    return 0;
}
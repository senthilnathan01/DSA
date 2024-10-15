#include <iostream>
#include<vector>

using namespace std;

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].
*/

// Using Linear Search:
vector<int> searchRange_linear(vector<int>& nums, int target) {
    vector<int> ans(2,-1);
    int t = nums.size();
    // Last poisition
    while(t--){
        if(nums[t]==target){
            ans[1]=t;
            break;
        }
    }

    // First position
    for(int i = 0; i<nums.size();i++){
        if(nums[i]==target){
            ans[0]=i;
            break;
        }
    }
    return ans;
}

// Using Binary Search:
int lower_bound(vector<int>& nums, int low, int high, int target){
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]<target) low = mid +1;
        else high = mid -1;
    }
    return low;
}

vector<int> searchRange_binary(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1, startPosition = -1, endPosition = -1;
    startPosition = lower_bound(nums, low, high, target);
    if(startPosition!=-1)
    {
        int endPosition = lower_bound(nums, low, high, target+1)-1;
    }

    return {startPosition, endPosition};
}   

int main() {
    vector<int> v = {1,2,3,5,5,5,6};
    vector<int> ans = searchRange_linear(v, 5);
    for(int num: ans){
        cout<<num<<" ";
    }
    cout<<endl;
    vector<int> ans2 = searchRange_binary(v, 5);
    for(int num: ans){
        cout<<num<<" ";
    }
    return 0;
}

// OUTPUT:
// 3 5
// 3 5
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
*/

// Approach 1: Using Hashing
// TC = O(NLogN + N)
// SC = O(N)

int majorityElement1(vector<int>& nums) {
    unordered_map <int, int> mpp;
    for(int num: nums) mpp[num]++;
    for(auto it: mpp) if(it.second > (nums.size()/2)) return it.first;
    return -1;
}

// Approach 2:
// Apply moore's voting algorithm
// TC = O(N)
// SC = O(1)
int majorityElement2(vector<int>& nums)
{
    int cnt = 0;
    int el;
    int n = nums.size();
    for(int i = 0; i<n; i++)
    {
        if(cnt==0)
        {
            cnt = 1;
            el = nums[i];
        }
        else if(el == nums[i])
        {
            cnt++;
        }
        else 
        {
            cnt--;
        }
    }
    cnt = 0;
    // Check if that element is the majority
    for(int i = 0; i<n; i++) if(nums[i]==el) cnt++;

    if(cnt>n/2) return el;
    else return -1;
}

int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    cout<<majorityElement1(nums)<<endl;
    cout<<majorityElement2(nums)<<endl;
}

// OUTPUT:
// 2
// 2
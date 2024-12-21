#include<iostream>
#include<vector>

using namespace std;

/*
Problem:
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.
*/

int lessThanEqualTo(vector<int> nums, int k)
{
    if(k<0) return 0;

    int l = 0, r = 0, n = nums.size(), cnt = 0, totcnt = 0;
    while(r<n)
    {
        if(nums[r]%2!=0) cnt++;
        while(cnt>k)
        {
            if(nums[l]%2!=0) cnt--;
            l++;
        }
        totcnt += (r-l+1);
        r++;
    }
    return totcnt;
}

int niceSubarrays(vector<int> nums, int k)
{
    return (lessThanEqualTo(nums, k)-lessThanEqualTo(nums, k-1));
}

int main()
{
    vector<int> nums = {1,1,2,1,1};
    int k = 3;
    cout<<niceSubarrays(nums, k);
}

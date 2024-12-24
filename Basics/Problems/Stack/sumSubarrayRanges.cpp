#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
You are given an integer array nums. 
The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

vector<int> nextSmaller(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = n-1; i>=0; i--)
    {
        while(!st.empty() && nums[st.top()]>=nums[i])
        {
            st.pop();
        }
        if(st.empty()) ans[i]= n;
        else ans[i]= st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);
    for(int i= 0; i<n; i++)
    {
        while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> nextGreater(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = n-1; i>=0; i--)
    {
        while(!st.empty() && nums[st.top()]<=nums[i])
        {
            st.pop();
        }
        if(st.empty()) ans[i]= n;
        else ans[i]= st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevGreater(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);
    for(int i= 0; i<n; i++)
    {
        while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

long long subArrayRanges(vector<int>& nums) {
    vector<int> nextSmallerIndex = nextSmaller(nums), prevSmallerIndex = prevSmaller(nums), nextGreaterIndex = nextGreater(nums), prevGreaterIndex = prevGreater(nums);
    long long sum = 0LL;
    for(int i = 0; i<nums.size(); i++)
    {
        long long minRange = (i-prevSmallerIndex[i])*(nextSmallerIndex[i]-i);
        long long maxRange = (i-prevGreaterIndex[i])*(nextGreaterIndex[i]-i);
        sum+= nums[i]*(maxRange - minRange); 
    }
    return sum;
}

int main()
{
    vector<int> nums = {4,-2,-3,4,1};
    cout<<subArrayRanges(nums)<<endl;
    return 0;
}

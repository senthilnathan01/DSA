#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. 
If it doesn't exist, return -1 for this number.
*/

vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> given = nums;
    given.insert(given.end(), nums.begin(), nums.end());
    // find nge for given
    stack<int> st;
    int n = given.size();
    vector<int> nge(n);
    for(int  i = n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()<=given[i]) st.pop();
        if(st.empty()) nge[i] = -1;
        else nge[i] = st.top();
        st.push(given[i]);
    }   
    return vector<int> (nge.begin(), nge.begin()+n/2);
}

int main()
{
    vector<int> nums = {1,2,3,4,3};
    vector<int> ans = nextGreaterElements(nums);
    for(int num: ans) cout<<num<<" ";
    return 0;
}

// OUTPUT:
// 2 3 4 -1 4 
/*
You are given an array arr[] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1

LINK: https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
*/

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top() <= arr[i]) st.pop();
            
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            
            st.push(arr[i]);
        }
        
        return ans;
    }
};

// Stacks

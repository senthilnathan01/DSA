#include<iostream>
#include<vector>
#include<stack>

using namespace std;

/*
Given an array, find the nearest smaller element G[i] for every element A[i] in the array such that the element has an index smaller than i.

More formally,

    G[i] for an element A[i] = an element A[j] such that 
    j is maximum possible AND 
    j < i AND
    A[j] < A[i]
Elements for which no smaller element exist, consider next smaller element as -1.

Input Format

The only argument given is integer array A.
Output Format

Return the integar array G such that G[i] contains nearest smaller number than A[i].If no such element occurs G[i] should be -1.
*/

vector<int> prevSmaller(vector<int> &A) {
    stack<int> st;
    int n = A.size();
    vector<int> G(n);
    for(int i= 0; i<n; i++)
    {
        while(!st.empty() && st.top()>=A[i]) st.pop();
        if(st.empty()) G[i] = -1;
        else G[i] = st.top();
        st.push(A[i]);
    }
    return G;
}

int main()
{
    vector<int> nums = {1,2,3,4,3};
    vector<int> ans = prevSmaller(nums);
    for(int num: ans) cout<<num<<" ";
    return 0;
}

// OUTPUT:
// -1 1 2 3 2  
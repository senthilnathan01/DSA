#include<iostream>
#include<stack>
#include<vector>

using namespace std;

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

// Approach 1:
// TC = O(3N) => O(N)
// SC = O(2N) (Can be done with O(N) also easily)
int trap1(vector<int>& height) {
    int n = height.size();
    vector<int> maxRight(n);
    vector<int> maxLeft(n);
    maxRight[n-1] = height[n-1];
    maxRight[0] = height[0];
    for(int i = n-2; i>=0; i--)
    {
        maxRight[i] = max(maxRight[i+1], height[i]);
    }
    for(int i = 1; i<n; i++)
    {
        maxLeft[i] = max(maxLeft[i-1], height[i]);
    }
    int sum = 0;
    for(int i = 1; i<n-1; i++)
    {
        sum += min(maxLeft[i], maxRight[i]) - height[i];
    }
    return sum;
}

// Approach 2 (Using two pointers)( Better Complexity)
// TC = O(N)
// SC = O(1)
int trap2(vector<int>& height) {
    int leftMax = 0, rightMax = 0, n = height.size(), l = 0, r = n-1, tot = 0;
    while(l<r)
    {
        if(height[l]<=height[r])
        {
            if(leftMax>height[l]) tot += (leftMax - height[l]);
            else leftMax = height[l];
            l++;
        }
        else
        {
            if(rightMax>height[r]) tot += (rightMax - height[r]);
            else rightMax = height[r];
            r--;
        }
    }
    return tot;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trap1(height)<<endl;
    cout<<trap2(height);
    return 0;
}
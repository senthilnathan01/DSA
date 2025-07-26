/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Leetcode Link: https://leetcode.com/problems/trapping-rain-water/description/
*/
// Solution 0: 
// Brute Force Solution of iterating through the vector and iterating through the vector for each height to find leftMax and rightMax is skipped
// TC for that O(N^2)

// Solution 1:
// Nice TC = O(n) solution 
// But SC is still high (O(n))
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n);
        int lh = 0, rh = 0;
        for(int i = 0; i < n; i++)
        {
            lh = max(lh, height[i]);
            maxLeft[i] = lh;
        }
        int ans = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            rh = max(rh, height[i]);
            ans += max(min(rh, maxLeft[i])-height[i], 0);
        }
        return ans;
    }
};

// Solution 2:
// Use Two Pointers
// SC = O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n -1;
        int lMax = height[l], rMax = height[r];
        int ans = 0;
        while(l < r)
        {
            if(lMax < rMax)
            {
                l++;
                lMax = max(lMax, height[l]);
                ans += lMax - height[l];
            }
            else
            {
                r--;
                rMax = max(rMax, height[r]);
                ans += rMax - height[r];
            }
        }
        return ans;
    }
};

// Solution 3:
// SC = O(1) here
// The key is to use Two Pointers

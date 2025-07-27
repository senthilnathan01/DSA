/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

Leetcode Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/

// Solution 1:
// Let's start with Brute Force
// Take every box and get its left and right boundaries -> gives max width for that height of the box
// Get the area every times -> Get the max of the area

// TC = O(N^2) - High? I know!
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int maxArea = 0;
        for(int i = 0; i < n; i++)
        {
            int height = heights[i];

            // Get the right boundary
            int rightB = i+1;
            while(rightB < n && heights[rightB] >= height) rightB++;

            int leftB = i;
            while(leftB >= 0 && heights[leftB] >= height) leftB--;

            rightB--;
            leftB++;

            maxArea = max(maxArea, height * (rightB - leftB + 1));
        }

        return maxArea;
    }
};

// Solution 2:
// Same concept as before but we are optimising the process of finding leftB and rightB
// TC = O(N) here

// We will be using Stacks for this
// And solution 3 and 4 also uses Stack but optimises the process further
// Watch NeetCode video solution for detailed explanation. Its good!

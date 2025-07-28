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
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Initialise the leftB and rightB
        vector<int> leftB(n, -1);
        vector<int> rightB(n, n);

        // We use stack to store the indices
        stack<int> st;

        // Get the left Boundaries
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(!st.empty()) leftB[i] = st.top();

            st.push(i);
        }

        // For ex:
        // Heights= [ 2,  1, 5, 6, 2, 3]
        // leftB  = [-1, -1, 1, 2, 1, 4]

        // Clear the stack
        st = {};

        // Get the right boundaries
        // Just do the same thing as before but iterate from right to left
        for(int i = n- 1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(!st.empty()) rightB[i] = st.top();

            st.push(i);
        }

        // For ex:
        // Heights= [ 2,  1, 5, 6, 2, 3]
        // leftB  = [-1, -1, 1, 2, 1, 4] -> [0, 0, 2, 3, 2, 5]
        // rightB = [ 1,  6, 3, 4, 6, 6] -> [0, 5, 2, 3, 5, 5]

        // Get the max Area
        int maxArea = 0;
        for(int i = 0; i < n; i++)
        {
            leftB[i]++;
            rightB[i]--;
            maxArea = max(maxArea, heights[i]*(rightB[i]-leftB[i]+1));
            // We add 1 cuz we include the area of the box i itself 
        }   

        return maxArea;
    }
};

// Solution 3:
// Let's use stack again but with one pass

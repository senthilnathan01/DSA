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
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st; // {index, height}

        int n = heights.size();

        for(int i = 0; i < n; i++)
        {
            int start = i;
            while(!st.empty() && st.top().second > heights[i])
            {
                pair<int, int> t = st.top();
                int index = t.first;
                int height = t.second;
                maxArea= max(maxArea, height*(i-index));
                start = index;
                st.pop();
            }
            st.push({start, heights[i]});
        }

        // Dry Run of the above process
        // i = 0
        // st is empty
        // {0, 2} is pushed to st

        // i = 1
        // st is not empty
        // 2 > 1
        // maxArea = 2
        // start = 1
        // {0, 2} is popped
        // {1, 1} is pushed

        // i = 2
        // st is not empty
        // 1 < 5
        // {2, 5} is pushed

        // i = 3
        // st is not empty
        // 5 < 6
        // {3, 6} is pushed

        // i = 4
        // st is not empty
        // 6 > 2
        // maxArea = 6
        // start = 3
        // maxArea = 10
        // start = 2
        // {2, 2} is pushed

        // i = 5
        // st is not empty
        // 1 < 3
        // {5, 3} is pushed

        // St is still not empty -> we need to calculate few more areas and update the maxArea

        while(!st.empty())
        {
            int index = st.top().first;
            int height = st.top().second;
            maxArea = max(maxArea, height*(static_cast<int>(heights.size())  - index));
            // These have right boundary at the end
            st.pop();
        }

        return maxArea;
    }
};

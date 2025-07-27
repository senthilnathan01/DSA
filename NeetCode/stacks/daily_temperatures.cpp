/*
Given an array of integers temperatures represents the daily temperatures, return an array answer 
such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.

Leetcode Link: https://leetcode.com/problems/daily-temperatures/description/
*/

// Solution 1: 
// Brute Force Approach
// TC = O(N^2)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // Let's do brute force approach first
        // We iterate through the days and look for the day with higher temp
        
        // Initialise the ans
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++)
        {
            int days = 1;
            for(int j = i + 1; j < n; j++)
            {
                if(temperatures[j]>temperatures[i])
                {
                    ans[i] = days;
                    break;
                }
                else
                {
                    days++;
                }
            }
        }

        return ans;
    }
};

// Solution 2:
// Best TC and SC
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        
        // will be using to mark those days that don't have any days ahead of it 
        // with higher temperatures
        int hottest = 0; // initialisation 
        
        for(int i = n - 1; i >=0 ; i--)
        {
            int currTemp = temperatures[i];
            if(currTemp >= hottest)
            {
                hottest = currTemp; // Update the hottest
                continue;
            }

            int days = 1;
            // Search for hotter day
            while(temperatures[i+days] <= temperatures[i])
            {
                days += ans[i+days];
            }
            // Found a hotter day
            ans[i] = days;
        }
        return ans;
    }
};

// Solution 3: 
// Shall we solve using stack
// Here we use stack and iterate from right to left (practically we will reach the ans sooner than 
// Iterating from left to right
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // stores indices of days with unresolved warmer temps

        for (int i = n - 1; i >= 0; --i) {
            // Pop all temperatures less than or equal to the current one
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            // If stack is not empty, we found a warmer day
            if (!st.empty()) {
                answer[i] = st.top() - i;
            }

            st.push(i);
        }

        return answer;
    }
};

// Solution 4:
// Attaching the solution 3(but iterating from left to right) for clarity
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stack; // pair: {temp, index}

        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!stack.empty() && t > stack.top().first) {
                auto pair = stack.top();
                stack.pop();
                res[pair.second] = i - pair.second;
            }
            stack.push({t, i});
        }
        return res;
    }
};

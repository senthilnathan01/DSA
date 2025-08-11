/*
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and 
wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. 
The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

LeetCode Link: https://www.geeksforgeeks.org/problems/geek-jump/1
*/

class Solution {
  public:
    vector<int> cost;
    int getCost(int idx, vector<int> &height)
    {
        if(idx == 0)
        {
            return 0;
        }
        if(idx < 0)
        {
            return -1;
        }
        
        int ans = INT_MAX;
        if(idx > 0 && cost[idx-1] == -1)
        {
            cost[idx -1] = getCost(idx-1, height);
        }
        
        if(idx > 1 && cost[idx-2] == -1)
        {
            cost[idx -2] = getCost(idx-2, height);
        }

        if(idx>0) ans = min(ans, cost[idx - 1] + abs(height[idx] - height[idx-1]));
        if(idx>1) ans = min(ans, cost[idx - 2] + abs(height[idx] - height[idx-2]));
        
        return ans;
    }
    
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        cost.assign(n, -1);
        return getCost(n-1, height);
    }
};

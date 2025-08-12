/*
A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k.

To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. 
The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by 
the frog to go from the 0th step to the (n-1)th step.

Link: https://takeuforward.org/plus/dsa/problems/frog-jump-with-k-distances
*/

class Solution {
public:
    int getMinEnergy(int idx, int k, vector<int> &minEnergy, vector<int> &heights)
    {
        if(idx==0) return 0;

        if(minEnergy[idx]!= -1) return minEnergy[idx];
        minEnergy[idx] = INT_MAX;

        for(int i = idx-1; i >=0 && i >= idx -k; i--)
        {
            if (minEnergy[i] == -1) minEnergy[i] = getMinEnergy(i, k, minEnergy, heights);
            minEnergy[idx] = min(minEnergy[idx], minEnergy[i] + abs(heights[i] - heights[idx]));
        }
        return minEnergy[idx];
    }   
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> minEnergy(n, -1);
        return getMinEnergy(n-1, k, minEnergy, heights);
    }
};

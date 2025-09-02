// LINK: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

class Solution {
public:
    vector<vector<int>> dp;

    int func(int i, int j, vector<int>& cuts) {
        if (j - i <= 1) return 0;  // no stick between -> no cost
        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int cost = (cuts[j] - cuts[i]) 
                     + func(i, k, cuts) 
                     + func(k, j, cuts);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        dp.assign(m, vector<int>(m, -1));

        return func(0, m - 1, cuts);
    }
};

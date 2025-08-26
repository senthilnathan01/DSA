/*
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n 
to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.

Link: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/
*/


#define ll long long 

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2;
        ll totSum = accumulate(nums.begin(), nums.end(), 0LL);

        // Helper function to get all the subset's sum
        auto getAllSubsetSums = [&](auto begin_it, auto end_it){
            vector<unordered_set<int>> res(n+1);
            res[0].insert(0);

            for(auto it = begin_it; it != end_it; it++){
                for(int size = n-1; size>=0; size--){
                    if(!res[size].empty()){
                        for(auto s: res[size]){
                            res[size+1].insert(s+*it);
                        }
                    }
                }
            }   
            return res;
        };

        // Get the subsets' sums for left half and right half
        vector<unordered_set<int>> leftSubsetSums = getAllSubsetSums(nums.begin(), nums.begin() + n);
        vector<unordered_set<int>> rightSubsetSums = getAllSubsetSums(nums.begin() + n, nums.end());

        // Convert the right half to vector and sort it for easy search process (we are gonna do binary search)
        vector<vector<int>> rightSums(n+1);
        for(int i = 0; i <= n; i++)
        {
            rightSums[i].assign(rightSubsetSums[i].begin(), rightSubsetSums[i].end());
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        ll min_diff = LLONG_MAX;

        for(int k = 0; k <= n; k++){
            for(int s1 : leftSubsetSums[k]){
                auto &r_sums = rightSums[n-k];

                if(r_sums.empty()) continue;

                double s2_target = (double)totSum/2.0 - s1;
                auto it = lower_bound(r_sums.begin(), r_sums.end(), s2_target);

                if(it!=r_sums.end()){
                    min_diff = min(min_diff, abs(totSum - 2*(s1 + (*it))));
                }

                if(it!=r_sums.begin()){
                    min_diff = min(min_diff, abs(totSum - 2*(s1 + (*(prev(it))))));
                }
            }
        }

        return (int)min_diff;
    }
};

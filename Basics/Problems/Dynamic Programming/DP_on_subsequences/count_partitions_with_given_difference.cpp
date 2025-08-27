/*
Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. 
  Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in 
which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

  Link: https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
*/

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int totSum = accumulate(arr.begin(), arr.end(), 0);
        
        int target = (d+totSum);
        
        if(target &1) return 0;
        
        target/=2;
        
        vector<int> dp(target+1);
        dp[0] = 1;
        
        for(int num: arr)
        {
            for(int j = target; j >=num; j--)
            {
                dp[j] = dp[j] + dp[j-num];
            }
        }
        
        return dp[target];
    }
};

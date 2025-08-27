class Solution {
  public:
    int countSubsets(int i, int currSum, int target, vector<int> &arr, vector<vector<int>> &memo)
    {
        // Base Case
        // Reached the end (considered all the elements for the sum)
        if(i == arr.size())
        {
            return (currSum == target);
        }
        
        // Check if it is already there in the memo
        if(memo[i][currSum]!=-1) return memo[i][currSum];
        
        // Exclude the next element
        int exclude = countSubsets(i+1, currSum, target, arr, memo);
        
        // Include the next element
        int include = 0;
        if((arr[i] + currSum) <= target)
        {
            include = countSubsets(i+1, currSum + arr[i], target, arr, memo);
        }
        
        return memo[i][currSum] = include + exclude;
    }
    
    int perfectSum(vector<int>& arr, int target) {
        // Recursive Approach
        int n = arr.size();
        
        vector<vector<int>> memo (n+1, vector<int>(target+1, -1));
        
        return countSubsets(0, 0, target, arr, memo);
    }
};

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // Tabulation Approach
        int n = arr.size();
        
        vector<vector<int>> dp (n+1, vector<int>(target+1, 0));
        
        dp[0][0] = 1;
        
        for(int i = 1; i<=n; i++){
            for(int j = 0; j <= target; j++){
                dp[i][j] = dp[i-1][j];
                
                if(j>=arr[i-1]){
                    dp[i][j] += dp[i-1][j-arr[i-1]];
                }
            }
        }
        
        return dp[n][target];
    }
};

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // Space optimized Approach
        int n = arr.size();
    
        vector<int> prev(target + 1, 0), curr(target + 1, 0);
        
        prev[0] = 1;
        
        for(int i = 1; i<=n; i++){
            curr = prev;
            for(int j = 0; j <= target; j++){
                if(j>=arr[i-1]){
                    curr[j] += prev[j - arr[i-1]];
                }
            }
            prev = curr;
        }
        
        return curr[target];
    }
};


// Generate all those subsequences whose sum is k

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> newVec;
        func(0, ans, newVec, nums);
        return ans;
    }

    void func(int idx, vector<vector<int>> &ans, vector<int> &newVec, vector<int>& nums, int sum, int k)
    {
        if(idx==nums.size())
        {
            if(sum==k)
            {
                ans.push_back(newVec);
            }
        }

        // Include current element
        newVec.push_back(nums[idx]);
        sum += nums[idx];
        func(idx +1, ans, newVec, nums, sum, k);

        // Exclude current element
        newVec.pop_back();
        sum -= nums[idx];
        func(idx +1, ans, newVec, nums, sum, k);
    }
};

// Generate one subsequence whose sum is k
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> newVec;
        func(0, ans, newVec, nums);
        return ans;
    }

    bool func(int idx, vector<vector<int>> &ans, vector<int> &newVec, vector<int>& nums, int sum, int k)
    {
        if(idx==nums.size())
        {
            if(sum==k)
            {
                ans.push_back(newVec);
                return true;
            }
            else return false;
        }

        // Include current element
        newVec.push_back(nums[idx]);
        sum += nums[idx];
        if(func(idx +1, ans, newVec, nums, sum, k) == true)
        {
            return true;
        }
        newVec.pop_back();
        sum -= nums[idx];

        // Exclude current element
        if(func(idx +1, ans, newVec, nums, sum, k) == true)
        {
            return true;
        }
        return false;
    }
};

// Count the number of subsequences with sum k
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> newVec;
        func(0, ans, newVec, nums);
        return ans;
    }

    int func(int idx, vector<vector<int>> &ans, vector<int> &newVec, vector<int>& nums, int sum, int k)
    {
        if(idx==nums.size())
        {
            if(sum==k)
            {
                ans.push_back(newVec);
                return 1;
            }
            else return 0;
        }

        // Include current element
        newVec.push_back(nums[idx]);
        sum += nums[idx];
        int l = func(idx +1, ans, newVec, nums, sum, k);
        newVec.pop_back();
        sum -= nums[idx];

        // Exclude current element
        int r = func(idx +1, ans, newVec, nums, sum, k);
        return l + r;
    }
};

// These patterns can be found in other problems as well
// If you observe we have only made minor changes in each of the three codes but they can be used for different patterns

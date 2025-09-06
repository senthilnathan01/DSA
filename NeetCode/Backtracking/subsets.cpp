class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> newVec;
        func(0, nums.size(), newVec, nums);
        return ans;
    }

    void func(int i, int n, vector<int> &newVec, vector<int> &nums){
        if(i==nums.size()){
            ans.push_back(newVec);
            return;
        }

        // Include
        newVec.push_back(nums[i]);
        func(i+1, n, newVec, nums);
        newVec.pop_back();

        // Exclude
        func(i+1, n, newVec, nums);
    }
};

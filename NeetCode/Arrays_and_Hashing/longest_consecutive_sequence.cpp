/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/

// Solution 1:
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1) return nums.size();
        
        // Put them in a set
        // Cuz they are sorted and have no duplicates
        set<int> found;
        for(auto num: nums) found.insert(num);
        auto first = found.begin();
        first++; 
        auto second = found.begin();
        int count = 1;
        int maxcount = 1;
        for(; first != found.end(); ++first, ++second)
        {
            if(*first == *second + 1)
            {
                count++;
                maxcount = max(count, maxcount);
            }
            else count = 1;
        }
        return maxcount;
    }
};

// Solution 2:
// Instead of using a set 
// We can just sort the nums vector and add in one more condition in the checking process (to handle duplicates)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;

        sort(nums.begin(), nums.end());
        int count = 1;
        int maxCount = 1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i-1]==nums[i]) continue;
            else if(nums[i-1]==nums[i]-1)
            {
                count++;
                maxCount = max(maxCount, count);
            }
            else count = 1;
        }
        return maxCount;
    }
};

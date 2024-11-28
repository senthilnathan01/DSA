#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.
*/

// Approach: Using hash set
// TC = O(n){for storing} + O(1){for searching} + O(n){for counting the length of sequence}
// = O(2n)

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    int longest = 1;

    unordered_set<int> mySet;
    for(int num : nums) mySet.emplace(num);

    for(int num: mySet)
    {
        // If num is the first element in the sequence
        if(mySet.find(num-1) == mySet.end())
        {
            int cnt = 1;
            int x = num;
            // If next number of this sequence is present
            while(mySet.find(x+1) != mySet.end())
            {
                cnt++;
                x++;
            }
            longest=max(longest, cnt);
        }
    }

    return longest;
}
int main()
{
    vector<int> nums = {100,4,200,1,3,2,1,1};
    cout<<longestConsecutive(nums);
}







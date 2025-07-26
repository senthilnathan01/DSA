/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

LC Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int p1 = 0, p2 = n -1;
        while(p1<p2)
        {
            int sum = numbers[p1]+numbers[p2];
            if(sum==target) return {p1+1, p2+1};
            else if (sum > target) p2--;
            else p1++;
        }
        return {0,0};
    }
};

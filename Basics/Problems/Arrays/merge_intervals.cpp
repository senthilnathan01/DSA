/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and 
return an array of the non-overlapping intervals that cover all the intervals in the input.
LINK: https://leetcode.com/problems/merge-intervals/description/
*/  

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.empty()) return ans;
        
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int i = 1; 
        int start = intervals[0][0];
        int end = intervals[0][1];
        while(i<n){
            int temp_start = intervals[i][0];
            int temp_end = intervals[i][1];
            if(temp_start>end){
                ans.push_back({start, end});
                start = temp_start;
                end = temp_end;
            }
            else end = max(temp_end, end);
            i++;
        }
        ans.push_back({start, end});
        return ans;
    }
};

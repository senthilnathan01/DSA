/*
You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] 
is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

LINK: https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
*/
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        vector<pair<int, int>> arr(n);
        for(int i =0;i < n; i++) arr[i] = {start[i], end[i]};
        
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){return a.second < b.second;});
        
        int ans = 0;
        int curr_end = -1;
        for(int i  = 0; i < n; i++){
            if(arr[i].first > curr_end){
                ans++;
                curr_end = arr[i].second;
            }
        }
        return ans;
    }
};

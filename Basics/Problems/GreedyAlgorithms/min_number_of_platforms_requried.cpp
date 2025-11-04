/*
Given arrival arr[] and departure dep[] times of trains on the same day, find the minimum number of platforms needed so that no train waits. 
A platform cannot serve two trains at the same time; if a train arrives before another departs, an extra platform is needed.

Note: Time intervals are in the 24-hour format (HHMM) , where the first two characters represent hour (between 00 to 23 ) and 
the last two characters represent minutes (this will be <= 59 and >= 0). Leading zeros for hours less than 10 are optional (e.g., 0900 is the same as 900).

LINK: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#medium
*/

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int cnt = 0;
        int ans = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < n && dep[j] < arr[i]){
                cnt--;
                j++;
            }
            cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

/*
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
LINK: https://leetcode.com/problems/minimum-time-difference/description/
*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> time(n);
        for(int i = 0; i < n; i++){
            string s = timePoints[i];
            int hr = stoi(s.substr(0, 2));
            int min = stoi(s.substr(3, 2));

            time[i] = 60*hr + min;
        }
        sort(time.begin(), time.end());
        vector<int> diff(n);
        for(int i = 0; i < n-1; i++) diff[i]=time[i+1]-time[i];
        diff[n-1]=time[0]+1440 - time[n-1];

        return *min_element(diff.begin(), diff.end());
    }
};

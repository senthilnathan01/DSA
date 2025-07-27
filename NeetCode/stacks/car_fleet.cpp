/*
There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.

Leetcode Link: https://leetcode.com/problems/car-fleet/description/
*/

// Solution using stack concept
// We also sort elements before. So stack is not used that much. It can be replaced with other things that have same functionality. 
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Storing position and speed in convenient manner (pair)
        vector<pair<int, int>> p;
        int n = position.size();
        for(int i = 0; i < n; i++)
        {
            p.push_back({position[i], speed[i]});
        }

        // Sort them according to their
        // Order: car closer to the target -> car far away from the target
        sort(p.rbegin(), p.rend());

        vector<double> st;
        // This stack is gonna store the time
        for(auto pp: p)
        {
            double time = (double)(target-pp.first)/pp.second;
            st.push_back(time);
            if(st.size()>=2 && st.back()<=st[st.size()-2]) st.pop_back();
        }
        return st.size();
    }
};

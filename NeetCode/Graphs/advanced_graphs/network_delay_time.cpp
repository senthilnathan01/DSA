/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), 
where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. 
If it is impossible for all the n nodes to receive the signal, return -1.

LINK: https://leetcode.com/problems/network-delay-time/description/
*/
class Solution {
public:
    typedef pair<int, int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<P>> adj(n+1);
        for(auto it: times) adj[it[0]].push_back({it[1], it[2]});

        vector<int> myTimes(n+1, 1e9);
        myTimes[0] = 0;
        myTimes[k] = 0;

        priority_queue<P, vector<P>, greater<P>> mH;
        mH.push({0, k});
        while(!mH.empty()){
            int time = mH.top().first;
            int node = mH.top().second;
            mH.pop();

            for(auto temp: adj[node]){
                int newTime = time + temp.second;
                int newNode = temp.first;

                if(myTimes[newNode]>newTime){
                    myTimes[newNode] = newTime;
                    mH.push({newTime, newNode});
                }
            }
        }
        int ans = *max_element(myTimes.begin(), myTimes.end());
        return ans==1e9 ? -1: ans;
    }
};

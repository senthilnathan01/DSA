/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times 
as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is 
the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive 
the signal. If it is impossible for all the n nodes to receive the signal, return -1.
*/

class Solution {
public:
    typedef pair<int, int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Get the adjacency matrix
        // {node, time}
        vector<vector<P>> adj (n+1);
        for(auto it: times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> myTime (n+1, 1e9); 
        myTime[0] = 0;
        myTime[k] = 0;
        // {time, node}
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, k});

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int time = it.first;
            int node = it.second;

            for(auto temp: adj[node])
            {
                int newtime = time + temp.second;
                int newnode = temp.first;

                if(myTime[newnode]>newtime)
                {
                    myTime[newnode] = newtime;
                    pq.push({newtime, newnode});
                }
            }
        }
        if(*max_element(myTime.begin(), myTime.end())==1e9) return -1;
        else return *max_element(myTime.begin(), myTime.end());
    }
};

/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional 
roads between some intersections. The inputs are generated such that you can reach any intersection 
from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that 
there is a road between intersections ui and vi that takes timei minutes to travel. You want to know 
in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. 
Since the answer may be large, return it modulo 109 + 7.
*/

class Solution {
public:
    typedef long long int ll;
    typedef pair<ll, ll> P;
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = (int)(1e9 + 7);
        vector<vector<P>> adj (n);
        for(auto it: roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<ll> dist(n, 1e12), ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;
        pq.push({0, 0});
        while(!pq.empty())
        {
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for(auto it: adj[node])
            {
                ll adjNode = it.first;
                ll edW = it.second;

                if(dis + edW < dist[adjNode])
                {
                    dist[adjNode] = dis + edW;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};

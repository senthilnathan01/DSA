/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = 
  [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. 
  If there is no such route, return -1.

  LINK: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/
*/

class Solution {
public:
    using State = tuple<int, int, int>;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto &f: flights) adj[f[0]].push_back({f[1], f[2]});

        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, src, 0});

        // Cost Table: [node][stops] = minCost
        vector<vector<int>> cost(n, vector<int>(k+2, INT_MAX));
        cost[src][0] = 0;

        while(!pq.empty()){
            auto [price, node, stops] = pq.top(); pq.pop();

            if(node == dst) return price; 

            if(stops <=k){
                for(auto& [next, p]: adj[node]){
                    int newCost = price + p;
                    if(newCost < cost[next][stops + 1]){
                        cost[next][stops + 1] = newCost;
                        pq.push({newCost, next, stops + 1});
                    }
                }
            }
        } 

        return -1;
    }
};

// DP approach
// Using Bellman-Ford algo
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[src] = 0;

        // Run Bellman-Ford Algo for k+1 iterations
        // At most k stops = at most k cities in between = at most k+1 cities in total
        // Hence k+1 iterations in total
        for(int i = 0; i <= k; i++){
            vector<int> temp = dist;

            for(auto &f: flights){
                int u = f[0], v = f[1], w = f[2];
                if(dist[u]!=INF && dist[u]+w < temp[v]){
                    temp[v] = dist[u] + w;
                }
            }
            // update
            dist = temp;
        }
        return (dist[dst]==INF) ? -1: dist[dst];
    }
};

/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] 
= [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at 
most k stops. If there is no such route, return -1.
*/

class Solution {
public:
    // {stops, {node, cost}}
    typedef pair<int, pair<int, int>> P;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //{price, to}
        vector<vector<pair<int,int>>> routes (n);
        for(auto flight:flights)
        {
            routes[flight[0]].push_back({flight[2], flight[1]});
        }

        vector<int> cityCost (n, 1e9);
        // {stops, {node, cost}}
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {src, 0}});
        cityCost[src] = 0;

        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            int stops = temp.first;
            int node = temp.second.first;
            int cost = temp.second.second;

            if(stops>k) continue;

            for(auto flight: routes[node])
            {
                if(cost + flight.first < cityCost[flight.second])
                {
                    cityCost[flight.second] = cost + flight.first;
                    pq.push({stops + 1, {flight.second, cityCost[flight.second]}});
                }
            }
        }

        if(cityCost[dst] == 1e9) return -1;
        return cityCost[dst];
    }
};

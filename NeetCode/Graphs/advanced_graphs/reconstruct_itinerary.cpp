/*
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. 
Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

LINK: https://leetcode.com/problems/reconstruct-itinerary/description/
*/

class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> ans;

    void dfs(string u){
        auto &destinations = graph[u];
        while(!destinations.empty()){
            string v = destinations.top();
            destinations.pop();
            dfs(v);
        }
        ans.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &ticket: tickets) graph[ticket[0]].push(ticket[1]);

        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

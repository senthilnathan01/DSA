/*
You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. 
This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. 
xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. 
These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

LINK: https://leetcode.com/problems/detonate-the-maximum-bombs/
*/

class Solution {
public:
    int dfs(int node, vector<vector<int>> &adj, vector<bool> &visited){
        visited[node] = true;
        int cnt = 1;
        for(int neighbor: adj[node]){
            if(!visited[neighbor]) cnt += dfs(neighbor, adj, visited);
        }
        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0;
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i = 0;  i < n; i++){
            long long x1 = bombs[i][0], y1 = bombs[i][1], r = bombs[i][2];
            for(int j = 0; j < n; j++){
                if(i==j) continue;
                long long dx = bombs[j][0]-x1;
                long long dy = bombs[j][1]-y1;
                if(dx*dx + dy*dy <= r*r) adj[i].push_back(j);
            }
        }

        vector<bool> visited(n);
        for(int node = 0; node < n; node++){
            fill(visited.begin(), visited.end(), false);
            ans = max(ans, dfs(node, adj, visited));
        }
        return ans;
    }
};

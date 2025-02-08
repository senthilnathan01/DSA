// Here we also consider for situations with multiple connected componenets.
// For Problem Statement check out 
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color (n, -1);
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(check(i, n, graph, color) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool check(int start, int n, vector<vector<int>> &graph, vector<int> &color)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it: graph[node])
            {
                if(color[it] == -1)
                {
                    color[it] = !color[node];
                    q.push(it);
                }
                else if(color[it] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

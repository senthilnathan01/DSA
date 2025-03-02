/*
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections 
forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. 
Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two 
directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. 
If it is not possible, return -1. 
*/

class DisjointSet{
    public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n, 0); // 0 based indexing
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node)
    {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_u] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};

class Solution {
    public:
        int makeConnected(int n, vector<vector<int>>& connections) {
            DisjointSet ds(n);
            int countExtras = 0;
            for(auto it : connections)
            {
                int u = it[0];
                int v = it[1];
                if(ds.findUPar(u) == ds.findUPar(v))
                {
                    countExtras++;
                }
                else ds.unionBySize(u, v);
            }
            int countConnectedGraphs = 0;
            for(int i = 0; i < n; i++)
            {
                if(ds.parent[i] == i) countConnectedGraphs++;
            }
            int ans = countConnectedGraphs -1;
            if(countExtras >= ans) return ans;
            return -1;
        }
};

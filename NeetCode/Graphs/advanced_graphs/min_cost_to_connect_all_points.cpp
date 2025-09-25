/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

LINK: https://leetcode.com/problems/min-cost-to-connect-all-points/description/
*/

struct Edge{int src, dest, wt;};
bool cmp(Edge e1, Edge e2){return e1.wt < e2.wt;}

class Solution {
public:
    vector<int> parent, rank;
    int find(int u){
        if(parent[u]==u) return u;
        else return parent[u] = find(parent[u]);
    }

    void unite(int u, int v){
        int pu = find(u), pv = find(v);
        if(pu==pv) return;
        
        if(rank[pu]<rank[pv]){
            parent[pv] = pu;
            rank[pu]++;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;
        parent.resize(n+1);
        for(int i = 1; i <= n; i++) parent[i]=i;
        rank.assign(n+1, 1);

        for(int u = 1; u <= n; u++){
            for(int v = u+1; v <= n; v++){
                edges.push_back({u, v, abs(points[u-1][0]-points[v-1][0]) + abs(points[u-1][1]-points[v-1][1])});
            }
        }
        sort(edges.begin(), edges.end(), cmp);

        int ans = 0;
        for(int i = 0; i < edges.size(); i++){
            int src = edges[i].src, dest = edges[i].dest;
            if(find(src) != find(dest)){
                unite(src, dest);
                ans += edges[i].wt;
            }
        }

        return ans;
    }
};

// More Optimized Version using priority_queue and DSU
struct Edge{int w, u, v;};

struct DSU{
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1){iota(p.begin(), p.end(), 0);}
    int find(int u){return u==p[u]? u : p[u]=find(p[u]);}
    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu==pv) return false;
        if(sz[pu]<sz[pv]) swap(pu, pv);
        p[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto cmp = [](auto &a, auto&b){return a.w > b.w;};
        priority_queue<Edge, vector<Edge>, decltype(cmp)> pq(cmp);
        int n = points.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++) pq.push({abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]), i, j});
        }

        DSU dsu(n);
        int ans = 0;
        int cnt = 0;
        while(!pq.empty()){
            auto e = pq.top();
            pq.pop();
            int w = e.w, u = e.u, v = e.v;
            if(dsu.find(u)==dsu.find(v)) continue;
            dsu.unite(u, v);
            ans += w;
            if(cnt++ == n) break;
        }
        return ans;
    }
};

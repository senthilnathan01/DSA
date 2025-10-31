#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        size.resize(n+1, 1);
    }

    int find(int node){
        if(parent[node]==node) return node;
        return parent[node]= find(parent[node]);
    }

    long long unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return 0;
        if(size[a] < size[b]) swap(a, b);
        long long pairs = 1LL * size[a] * size[b];
        parent[b] = a;
        size[a] += size[b];
        return pairs;
    }
};


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m; cin>>n>>m;
    vector<array<int, 3>> edges(n-1);
    for(int i = 0; i < n-1; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges[i] = {w, u, v};
    }
    sort(edges.begin(), edges.end());

    vector<pair<int, int>> queries(m);
    for(int i= 0; i < m; i++){
        cin>>queries[i].first;
        queries[i].second = i;
    }
    sort(queries.begin(), queries.end());

    DSU dsu(n);
    vector<long long> ans(m);
    long long curr = 0;
    int j =0;

    for(auto &[q, idx]: queries){
        while(j < n-1 && edges[j][0] <= q){
            curr += dsu.unite(edges[j][1], edges[j][2]);
            ++j;
        }
        ans[idx] = curr;
    }

    for(auto a: ans) cout<<a<<" ";



    return 0;
}
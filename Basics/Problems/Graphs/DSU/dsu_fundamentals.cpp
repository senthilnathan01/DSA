#include <bits/stdc++.h>
using namespace std;

class DS{
    vector<int> parent, rank, size;
public:
    DS(int n){
        parent.resize(n+1);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n+1, 0);
        size.assign(n+1, 1);
    }

    int findP(int node){
        if(parent[node]==node) return node;
        else return parent[node]=findP(parent[node]);
    }

    void unionByRank(int u, int v){
        int pu = findP(u), pv = findP(v);
        if(pu==pv) return;

        int ru = rank[pu], rv = rank[pv];
        if(ru < rv){
            parent[pu] = pv;
        }
        else if(ru > rv){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void unionBySize(int u, int v){
        int pu = findP(u), pv = findP(v);
        if(pu==pv) return;

        if(size[pu]>size[pv]){
            parent[pv]=pu;
            size[pu] += size[pv];
        }
        else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

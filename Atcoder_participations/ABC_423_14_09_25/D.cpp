#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

struct Group {
    int id, c, b; ll a;
};

struct Departure {
    ll time; int size;
};

struct Compare {
    bool operator()(const Departure &a, const Departure &b) const {return a.time > b.time;}
};

int main() {
    int n; ll k; cin>>n>>k;
    vector<Group> g(n);
    for (int i = 0; i < n; i++) {
        cin>>g[i].a>>g[i].b>>g[i].c;
        g[i].id = i;
    }

    vector<ll> ans(n);
    queue<Group> q;
    priority_queue<Departure, vector<Departure>, Compare> pq;
    ll t = 0, inside_res = 0;

    int idx = 0;
    while(idx < n || !q.empty() || !pq.empty()){
        ll nextA = (idx < n ? g[idx].a : LLONG_MAX);
        ll nextD = (!pq.empty() ? pq.top().time : LLONG_MAX);

        if (!q.empty() && inside_res + q.front().c > k) t = nextD;
        else t = min(nextA, nextD);

        while (!pq.empty() && pq.top().time <= t) {
            inside_res -= pq.top().size;
            pq.pop();
        }

        while (idx < n && g[idx].a <= t) {
            q.push(g[idx]);
            idx++;
        }

        while (!q.empty() && inside_res + q.front().c <= k) {
            auto curr = q.front(); 
            q.pop();
            ans[curr.id] = t;
            inside_res += curr.c;
            pq.push({t + curr.b, curr.c});
        }
    }

    for(auto x : ans) cout<<x<<endl;
    return 0;
}

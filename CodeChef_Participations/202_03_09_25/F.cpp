#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 2e9 + 10;

struct Node{
    ll P, Q;
};

vector<ll> a;
vector<Node> tree;
int n;

Node merge(Node &left, Node &right){
    Node ans;
    ans.Q = min(left.Q, right.Q);
    ans.P = max(right.P, min(left.P, right.Q));
    return ans;
}

void build(int node, int start, int end){
    if(start == end){
        int a_idx = start;
        if(a_idx&1) tree[node] = {a[a_idx], INF};
        else tree[node] = {-INF, a[a_idx]};
        return;
    }

    int mid = start + (end-start)/2;
    build(2*node, start, mid);
    build(2*node + 1, mid +1, end);
    tree[node] = merge(tree[2*node], tree[2*node+1]);
}

void update(int node, int start, int end, int idx){
    if(start == end){
        int a_idx = start;
        if(a_idx&1) tree[node] = {a[a_idx], INF};
        else tree[node] = {-INF, a[a_idx]};
        return;
    }

    int mid = start + (end-start)/2;
    if(start <= idx && idx <=mid) update(2*node, start, mid, idx);
    else update(2*node+1, mid+1, end, idx);
    tree[node] = merge(tree[2*node], tree[2*node + 1]);
}

ll score(){
    if(n==1) return a[0];
    if(n==3) return min(a[2], max(a[0], a[1]));

    Node root = tree[1];
    ll w = max(root.P, min(a[0], root.Q));
    return min(a[n-1], max(a[n-2], w));
}

void solve()
{
    int q;
    cin>>n>>q;
    a.resize(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n>=5){
        tree.assign(4*(n-2), {0,0});
        build(1, 1, n-3);
    }

    cout<<score();

    while(q--){
        int p;
        ll x;
        cin>>p>>x;
        a[p-1] = x;
        if(n>=5 && p>=2 && p <= n-2) update(1, 1, n-3, p-1);
        cout<<" "<<score();
    }
    cout<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
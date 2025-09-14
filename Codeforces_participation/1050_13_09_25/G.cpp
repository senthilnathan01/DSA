#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

const int N = 200002;
vector<int> divs[N];
int freq[N];
int div_with_kcnt[N];
int st[4*N];

void precompute(){
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j+=i) divs[j].push_back(i);
    }
}

void update(int node, int start, int end, int idx, int cnt){
    if(start==end){
        st[node] = cnt;
        return;
    }
    int mid = (start + end)/2;
    if(start <= idx && idx <= mid) update(2*node, start, mid, idx, cnt);
    else update(2*node + 1, mid+1, end, idx, cnt);
    st[node] = max(st[2*node], st[2*node + 1]);
}

int query(int node, int start, int end, int l, int r){
    if(r < start || l > end || l > r) return 0;

    if(l<=start && end <= r) return st[node];

    int mid = (start + end)/2;
    return max(query(2*node, start, mid, l, r), query(2*node +1, mid +1, end, l, r));
}

void solve() 
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    fill(freq, freq + n + 1, 0);
    fill(div_with_kcnt, div_with_kcnt + n+1, 0);
    fill(st, st + 4*(n+1), 0);

    for(int i = 1; i <= n; i++){
        for(int d : divs[a[i-1]]){
            int prev_cnt = freq[d];
            if(prev_cnt>0){
                div_with_kcnt[prev_cnt]--;
                if(div_with_kcnt[prev_cnt]==0) update(1, 0, n, prev_cnt, 0);
            }

            freq[d]++;
            int curr_cnt = freq[d];
            div_with_kcnt[curr_cnt]++;
            if(div_with_kcnt[curr_cnt]==1) update(1, 0, n, curr_cnt, curr_cnt);
        }
        cout<<query(1, 0, n, 0, i-1)<<" ";
    }
    cout<<endl;
}

int main() {
    fast
    precompute();
    int t; cin>>t;
    while (t--) solve();
    return 0;
}

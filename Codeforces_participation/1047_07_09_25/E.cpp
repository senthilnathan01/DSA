#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

void func(vector<int> &tempA){
    int n = tempA.size();
    vector<int> freq(n+2, 0);
    for(int x: tempA) if(x <=n+1) freq[x]++;

    int mex = 0;
    while(mex <= n+1 && freq[mex]>0) mex++;

    vector<int> temp;
    temp.reserve(n);
    for(int x: tempA){
        if(x<mex && freq[x]==1) temp.push_back(x);
        else temp.push_back(mex);
    }
    tempA = temp;
}

void solve() 
{
    int n; cin>>n;
    ll k; cin>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    map<vector<int>, ll> mem;

    vector<ll> processSum;
    vector<int> tempA = a;
    for(ll process = 0; process < k; process++){
        func(tempA);
        vector<int> sortedA = tempA;
        sort(sortedA.begin(), sortedA.end());
        if(mem.count(sortedA)){
            ll start = mem[sortedA];
            ll len = process - start;

            ll rem = k - process -1;
            ll end = start + rem % len;
            cout<<processSum[end]<<endl;
            return;
        }
        mem[sortedA] = process;
        processSum.push_back(accumulate(tempA.begin(), tempA.end(), 0LL));
    }
    cout<<accumulate(tempA.begin(), tempA.end(), 0LL)<<endl;
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}

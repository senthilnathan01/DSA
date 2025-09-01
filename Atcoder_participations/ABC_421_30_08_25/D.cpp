#include<bits/stdc++.h>
using namespace std;

using ll = long long;

pair<ll, ll> getDelta(char ch){
    if(ch=='U') return {-1, 0};
    else if(ch == 'D') return {1, 0};
    else if(ch == 'R') return {0, 1};
    else return {0, -1};
}

int main(){
    ll rt, ct, ra, ca; cin>>rt>>ct>>ra>>ca;
    ll n, m, l; cin>>n>>m>>l;

    vector<pair<char, ll>> a_moves(m);
    for(int i = 0; i <m; i++) cin>>a_moves[i].first>>a_moves[i].second;

    vector<pair<char, ll>> b_moves(l);
    for(int i = 0; i < l; i++) cin>>b_moves[i].first>>b_moves[i].second;

    ll ans = 0;
    int a_i = 0, b_i = 0;
    while(a_i < m && b_i < l)
    {
        ll numProcess = min(a_moves[a_i].second, b_moves[b_i].second);

        pair<int, int> a_delta = getDelta(a_moves[a_i].first);
        pair<int, int> b_delta = getDelta(b_moves[b_i].first);

        ll dr = rt - ra;
        ll dc = ct - ca;

        ll rcr = a_delta.first - b_delta.first;
        ll rcc = a_delta.second - b_delta.second;

        if(rcr == 0 && rcc==0){
            if(dr==0 && dc==0) ans += numProcess;
        }
        else{
            ll jr = -1, jc = -1;

            if(rcr != 0){
                if(dr % rcr ==0) jr = -dr/rcr;
            }
            else if(dr == 0) jr = -2;

            if(rcc != 0){
                if(dc % rcc ==0) jc = -dc/rcc;
            }
            else if(dc == 0) jc = -2;

            ll j = -1;
            if(jr == -2) j = jc;
            else if(jc == -2) j = jr;
            else if(jr == jc) j = jr;

            if(j > 0 && j <= numProcess) ans ++;
        }

        rt += a_delta.first * numProcess;
        ct += a_delta.second * numProcess;

        ra += b_delta.first * numProcess;
        ca += b_delta.second * numProcess;

        a_moves[a_i].second -= numProcess;
        b_moves[b_i].second -= numProcess;

        if(a_moves[a_i].second == 0) a_i++;
        if(b_moves[b_i].second == 0) b_i++;
    }
    cout<<ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

void solve() 
{
    int n, k; cin>>n>>k;
    string s; cin>>s;

    int max_num = 0, curr_num = 0;
    vector<int> zero_idx, one_idx;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='1'){
            curr_num++;
            one_idx.push_back(i);
        }
        else{
            max_num = max(max_num, curr_num);
            curr_num = 0;
            zero_idx.push_back(i);
        }
    }
    max_num = max(max_num, curr_num);

    if(max_num >= k){
        cout<<"NO\n";
        return;
    }

    cout<<"YES\n";

    int j = n;
    vector<int> ans(n);
    for(int idx: zero_idx) ans[idx] = j--;
    for(int idx: one_idx) ans[idx] = j--;
    
    for(auto num: ans) cout<<num<<" ";
    cout<<'\n';
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

void solve() 
{
    int n; cin>>n;
    vector<pair<int, int>> index_b(n);
    map<int, int> counts;
    for(int i = 0; i <n; i++){
        int temp; cin>>temp;
        index_b[i] = {temp, i};
        counts[temp]++;
    }

    bool possi = true;
    for(auto p: counts){
        if(p.second % p.first != 0){
            possi = false;
            break;
        }
    }

    if(!possi){
        cout<<-1<<endl;
        return;
    }
    
    sort(index_b.begin(), index_b.end());
    vector<int> p;
    int curr = 1;
    int i = 0;
    while(i<n){
        int val = index_b[i].first;
        int cnt = counts[val];
        int numOfGroups = cnt/val;
        for(int j = 0; j < numOfGroups; j++){
            for(int k =0; k < val; k++) p.push_back(curr);
            curr++;
        }
        i+=cnt;
    }
    vector<int> a(n);
    for(int i = 0; i< n; i++) a[index_b[i].second] = p[i];
    for(int i = 0; i < n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}

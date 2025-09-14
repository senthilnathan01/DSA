#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{   
    int n, r; cin>>n>>r;
    vector<int> l(n+1);
    vector<int> prefix(n+1, 0);
    vector<int> unlocked;
    for(int i = 1; i <=n; i++){
        cin>>l[i];
        prefix[i] = prefix[i-1] + l[i];
        if(l[i]==0) unlocked.push_back(i);
    } 
    
    if(unlocked.empty()){
        cout<<0;
        return 0;
    }

    int start = unlocked.front(), end = unlocked.back();

    auto cost = [&](int l, int r){
        if(l>r) return 0;
        return r - l + 1 + prefix[r] - prefix[l-1];
    };

    int r1start = min(min(start -1, r)+1, start);
    int r1end = max(max(start -1, r), end);
    int cost1 = cost(r1start, r1end);

    int r2start = min(min(r, end)+1, start);
    int r2end = max(max(r, end), end);
    int cost2 = cost(r2start, r2end);
    
    cout<<min(cost1, cost2);
    return 0;
}
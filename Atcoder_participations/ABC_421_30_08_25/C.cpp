#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int n; cin>>n;
    string s; cin>>s;
    vector<int> a_i;
    for(int i = 0; i < 2*n; i++)if(s[i]=='A') a_i.push_back(i);
    ll cost1 = 0;
    for(int i = 0; i < n; i++) cost1 += abs(a_i[i]-(2*i));

    ll cost2 = 0;
    for(int i = 0; i < n; i++) cost2 += abs(a_i[i] - (2*i+1));

    cout<<min(cost1, cost2);

    return 0;
}
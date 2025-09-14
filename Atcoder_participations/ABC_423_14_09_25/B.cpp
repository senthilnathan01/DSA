#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    int n; cin>>n;
    vector<int> l(n+1);
    for(int i = 1; i <= n; i++) cin>>l[i];
    vector<int> left(n+1, 0), right(n+1, 0);
    left[0] = 1;
    for(int i = 1; i <= n; i++) if(left[i-1] && l[i]==0) left[i] =1;
    right[n] = 1;
    for(int i = n-1; i>=0; i--) if(right[i+1] && l[i+1]==0) right[i] = 1;
    int cnt = 0;
    for(int i = 0; i <= n; i++) if(!left[i]&&!right[i]) cnt++;
    cout<<cnt;
    return 0;
}
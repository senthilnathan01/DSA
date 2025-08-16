#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, m; cin>>n>>m;
    string s, t; cin>>s>>t;
    string temp;
    int l, r;

    vector<int> diff(n+1, 0);
    while(m--)
    {
        cin>>l>>r;
        diff[l-1]++;
        diff[r]--;
    }

    vector<int> swaps(n, 0);
    swaps[0] = diff[0];
    for(int i = 1; i < n; i++) swaps[i] = swaps[i-1] + diff[i];

    for(int i = 0; i < n; i++) 
    {
        if(swaps[i]&1) s[i] = t[i];
    }


    cout<<s;
    return 0;
}
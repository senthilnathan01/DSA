#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;

    int temp;
    unordered_map<int, int> freq;
    int freq1 = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        if(temp==1) freq1++;
        freq[temp]++;
    }
    
    int ans1 = n - freq1;

    int modeFreq = 0;
    for(auto const& [color, count]: freq)
    {
        if(count>modeFreq) modeFreq= count;
    }

    cout<<min(ans1, 1 + n - modeFreq)<<'\n';
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

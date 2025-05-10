#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

int solve()
{
    int n, m;cin>>n>>m;

    map<int, int> mpp;
    for(int i = 1; i <= m; i++) mpp[i] = 0;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        mpp[a[i]]++;
    }
    for(int i = 1; i <= m; i++)
    {
        if(mpp[i]==0) return 0;
    }

    int count = 0;
    for(int i = n-1; i >= 0; i--)
    {
        count++;
        mpp[a[i]]--;
        if(mpp[a[i]]==0) return count;
    }
}

int main()
{
    fast
    cout<<solve();
    return 0;
}


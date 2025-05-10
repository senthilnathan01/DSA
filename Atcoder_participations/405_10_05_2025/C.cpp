#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

long long solve()
{
    long long n; cin>>n;
    vector<long long> a(n);
    long long sum = 0;
    long long ss = 0;

    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum += a[i];
        ss += a[i]*a[i];
    }

    long long ans = (sum*sum - ss)/2;
    return ans;
}

int main()
{
    fast
    cout<<solve();
    return 0;
}


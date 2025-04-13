#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

bool solve(string &p, string &s)
{

    int i = 0, j = 0;
    int n = p.size(), m = s.size();

    while(i < n && j < m)
    {
        if(p[i] != s[j]) return false;

        char current = p[i];
        int cnt1 = 0, cnt2 = 0;

        while(i<n && p[i] == current)
        {
            cnt1++;
            i++;
        }

        while(j<m && s[j] == current)
        {
            cnt2++;
            j++;
        }
        
        if(cnt2 < cnt1 || cnt2 > 2*cnt1) return false;
    }

    if(i==n && j ==m) return true;
    else return false;
}

int main()
{
    fast
    int t; cin>>t;
    while(t--)
    {
        string p, s; cin>>p>>s;
        if(solve(p,s)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
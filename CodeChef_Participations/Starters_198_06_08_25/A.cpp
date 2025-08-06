#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> mpp;
    string s;
    cin>>s;
    for(int i = 0; i < 3; i++)
    {
        mpp[s[i]]++;
    }
    if(mpp['c']==1 && mpp['a']==1 && mpp['t']==1) cout<<"Yes";
    else cout<<"No";
    return 0;
}

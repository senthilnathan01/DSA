#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;

    while(t--)
    {
        int n; cin>>n;
        string s; cin>>s;
        int b = 0, g = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i]=='B') b++;
            else g++;
            if(b>2*g) break;
        }
        cout<<b+g<<endl;
    }


    return 0;
}

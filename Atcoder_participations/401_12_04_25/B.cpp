#include<bits/stdc++.h>

using namespace std;

int main()
{
    bool loggedIn = false;
    int n; cin>>n;
    int count = 0;
    string s;
    while(n--)
    {
        cin>>s;
        if(s=="login") loggedIn = true;
        else if(s=="logout") loggedIn = false;
        else if(s=="private")
        {
            if(loggedIn) continue;
            else count++;
        }
    }
    cout<<count;
    return 0;
}

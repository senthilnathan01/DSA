#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    //Rules
    // sick sick - ans = 1
    // sick fine - ans = 2
    // fine sick - ans = 3
    // fine fine - ans = 4
    if(s1=="sick")
    {
        if(s2 == "sick") cout<<1;
        else cout<<2;        
    }
    else
    {
        if(s2 == "sick") cout<<3;
        else cout<<4;
    }
    return 0;
}
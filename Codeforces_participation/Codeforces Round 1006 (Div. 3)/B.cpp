#include<iostream>
#include<string>
#include<cmath>
#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;
typedef long long ll;

ll solve()
{
    ll n; cin>>n;
    string s; cin>>s;
    ll up = 0, down = 0;
    for(ll i = 0; i < n; i++)
    {
        if(s[i]=='-') up++;
        else down++;
    }

    if(up%2==0)
    {
        return down*(pow((up/2),2));
    }
    else return down*(up/2)*(up/2 + 1);
}

int main()
{
    CODE
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}

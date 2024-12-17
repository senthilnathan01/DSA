#include<iostream>
#define CODE ios::sync_with_stdio(false); cin.tie(0);
#define ll long long int

using namespace std;

void solve()
{
    int m,a,b,c;
    cin>>m>>a>>b>>c;
    int num = 0;
    if(a<=m) num+=a;
    else num+= m;
    if(b<=m) num+=b;
    else num += m;
    int rem = 2*m - num;
    if(rem>0)
    {
        if(c<=rem) num+= c;
        else num+=rem;
    }
    cout<<num<<endl;
    
}

int main()
{
    CODE
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        solve();
    }
}
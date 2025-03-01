#include<iostream>
#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve()
{
    int n, a, b;
    cin>>n>>a>>b;
    if((abs(b-a))%2 == 0)
    {
        // Odd no of gaps
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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

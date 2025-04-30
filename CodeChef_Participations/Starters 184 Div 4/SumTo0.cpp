#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    if(n==1)
    {
        cout<<-1<<endl;
        return;
    }
    
    if(n%2==0)
    {
        int flag = 1;
        for(int i = 0; i < n; i++)
        {
            cout<<flag<<" ";
            flag *= -1;
        }
    }
    else
    {
        int i = n-1;
        int flag = 1;
        while(i>2)
        {
            cout<<flag<<" ";
            flag *= -1;
            i--;
        }
        cout<<3<<" "<<-1<<" "<<-2;
    }
    cout<<endl;
}

int main() {
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;   
}

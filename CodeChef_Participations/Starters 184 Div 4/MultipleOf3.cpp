#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int x = n/3;
    int y = n/3 + 1;
    if(abs(n-x*3)<abs(n-y*3))
    {
        cout<<x*3;
    }
    else cout<<y*3;
}

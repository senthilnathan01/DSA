#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b; cin>>a>>b;
    int num1 = min(a, b);
    int ans = num1*(num1-1) + num1*(abs(b-a));
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

ull f(ull n){
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoull(s);
}

int main()
{
    ull x, y; cin>>x>>y;
    ull prev1 = x;
    ull prev2 = y;
    ull curr;
    for(int i = 3; i <= 10; i++){
        curr = f(prev1 + prev2);
        prev1 = prev2;
        prev2 = curr;
    }   
    cout<<curr;
    return 0;
}
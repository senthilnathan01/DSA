#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y; cin>>n>>x>>y;
    int cakes_per_vehicle = y/x;
    cout<<(n+cakes_per_vehicle-1)/cakes_per_vehicle;
    return 0;
}

#include<iostream>
#include<vector>

using namespace std;

typedef unsigned long long int ull;

bool solve()
{
    int n;
    cin>>n;
    // Base Case
    if(n==2) return true;

    vector<ull> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];

    for(int i = 0; i<=n-3; i++)
    {
        ull a = arr[i+1]*arr[i+1];
        ull b = arr[i]*arr[i+2];
        if(a!=b) return false;
    }
    return true;
}
int main()
{
    if(solve()) cout<<"Yes";
    else cout<<"No";
}
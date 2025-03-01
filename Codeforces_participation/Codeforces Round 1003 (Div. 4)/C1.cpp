#include<iostream>
#include<vector>
#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve()
{
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int b;
    cin>>b;

    if(b-a[n-1]>a[n-1])
    {
        a[n-1] = b - a[n-1]; 
    }

    for(int i = n-2; i>=0; i--)
    {
        int newnum = b-a[i];
        int temp = a[i];
        if(a[i] > a[i+1])
        {
            a[i] = newnum;
        }
        if(a[i] > a[i+1])
        {
            cout<<"NO"<<endl;
            return;
        }
        if(temp < a[i+1] && newnum > temp && newnum <= a[i+1]) a[i] = newnum;
    }
    cout<<"YES"<<endl;
    return;
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

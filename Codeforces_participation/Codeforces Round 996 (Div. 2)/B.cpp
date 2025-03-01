#include<iostream>
#include<vector>
#include<algorithm>

#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<n; i++) cin>>b[i];
    vector<int> c(n);
    for(int i = 0; i<n; i++) c[i] = a[i]-b[i];

    //Check for deficiency
    int numDeficiency = 0;
    sort(c.begin(), c.end());
    if(c[0]>=0)
    {
        cout<<"YES"<<endl;
        return;
    }
    int indexPos = 0;
    int limiter = 0;
    for(int i = 0; i < n; i++)
    {
        if(c[i]>=0)
        {
            indexPos = i;
            limiter = c[i];
            break;
        }
    }
    if(indexPos>1)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(limiter<-c[0])
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        cout<<"YES"<<endl;
        return;
    }
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

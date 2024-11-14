#include <iostream>
#include<vector>

using namespace std;

void processTestCase(int n)
{
    vector<int> arr(n);
    for(int i = 0; i<n ; i++) cin>>arr[i];

    int past, current;
    past = arr[0];
    for(int i=1; i<n; i++)
    {
        current = arr[i];
        if(abs(current-past)!=5 && abs(current-past)!=7)
        {
            cout<<"NO"<<endl;
            return;
        }
        past = current;
    }
    cout<<"YES"<<endl;
    return;
}

void solve()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        processTestCase(n);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

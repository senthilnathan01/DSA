#include <iostream>

using namespace std;

void processTestCase(int n)
{
    int k;
    cin>>k;
    // Base Case
    if(k==1 || k==n)
    {
        if(n>1)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<1<<endl;
            cout<<1<<endl;
        }
    }

    // Other cases
    if(k%2==0)
    {
        cout<<3<<endl;
        cout<<1<<" "<<k<<" "<<k+1<<endl;
    }
    else
    {
        cout<<5<<endl;
        cout<<1<<" "<<k-1<<" "<<k<<" "<<k+1<<" "<<k+2<<endl;
    }
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

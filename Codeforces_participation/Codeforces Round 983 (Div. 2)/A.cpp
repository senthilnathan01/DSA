#include <iostream>
#include<algorithm>

using namespace std;

void processTestCase(int n)
{
    int no_zeros=0;
    int no_ones = 0;

    int no_of_bulbs = 2*n;
    int state = 0;
    while(no_of_bulbs--)
    {
        cin>>state;
        if(state==0) no_zeros++;
        else no_ones++;
    }
    cout<<(no_ones%2 + no_zeros%2)/2<<" "<<min(no_ones, no_zeros)<<endl;
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

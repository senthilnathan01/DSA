#include<iostream>
#include<string>
#include<cmath>
#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int solve()
{
    double n, k, p;
    cin>>n>>k>>p;
    
    // Base case - k = 0
    if(k==0) return 0;
    // k is positive
    if(k>0)
    {
        if(n*p < k) return -1;
        else if (n*p == k) return n;
        else return ceil(k/p);
    }
    // k is negative
    if(k<0)
    {
        k = -k;
        if(n*p < k) return -1;
        else if (n*p == k) return n;
        else return ceil(k/p);
    }
}

int main()
{
    CODE
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}

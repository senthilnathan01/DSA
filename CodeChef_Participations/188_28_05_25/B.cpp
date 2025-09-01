#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int max_time1 = 0;
        int temp = 0;
        int max_time2 = 0;
        int n; cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>temp;
            if(i%2==0) max_time1 += temp;
            else max_time2 += temp;
        }
        if(max_time1>max_time2) cout<<max_time1<<endl;
        else cout<<max_time2<<endl;
    }
    return 0;
}

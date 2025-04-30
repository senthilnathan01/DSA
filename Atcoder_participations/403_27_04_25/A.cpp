#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    int sum = 0;
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        if(i%2==0) sum += temp;
    }
    cout<<sum;
    return 0;
}

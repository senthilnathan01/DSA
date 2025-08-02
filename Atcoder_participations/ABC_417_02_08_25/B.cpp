#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int temp;
    map<int, int> mpp;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        mpp[temp]++;
    }

    for(int i = 0; i < m; i++)
    {
        cin>>temp;
        if(mpp.find(temp)!=mpp.end()) mpp[temp]--;
        if(mpp[temp]==0) mpp.erase(temp);
    }   
    for(auto p: mpp)
    {
        int times = p.second;
        for(int i = 0; i < times; i++) cout<<p.first<<" ";
    }
    return 0;
}

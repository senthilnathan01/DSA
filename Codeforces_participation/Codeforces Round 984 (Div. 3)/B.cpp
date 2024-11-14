#include <iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

void processTestCase(int n, int k)
{
    map<int, int> mpp;
    for(int i=0; i<k; i++)
    {
        int brand, cost;
        cin>>brand>>cost;

        mpp[brand]+=cost;
    }

    vector<int> sorted_sum;
    for(auto p: mpp) sorted_sum.push_back(p.second);

    sort(sorted_sum.begin(), sorted_sum.end());

    int length = sorted_sum.size();

    int i = length - 1;
    int total_sum = 0;

    while(n-- && i>=0)
    {
        total_sum += sorted_sum[i];
        i--;
    }
    cout<<total_sum<<endl;
}


void solve()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;
        processTestCase(n, k);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

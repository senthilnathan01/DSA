#include<iostream>
#include<vector>
#include<algorithm>

#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

pair<long long, long long> sumTheArray(vector<long long> &arr, long long m)
{
    long long totsum = 0;
    long long sum = 0;
    for(long long i = 0; i < m; i++)
    {
        sum += arr[i];
        totsum += sum;
    }
    return {totsum, sum};
}

void solve()
{
    long long n, m;
    cin>>n>>m;
    vector<vector<long long>> a(n, vector<long long> (m));
    for(long long i = 0; i < n; i++)
    {
        for(long long j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }

    vector<pair<long long, long long>> sumArray (n);
    for(long long i = 0; i < n; i++)
    {
        sumArray[i] = sumTheArray(a[i], m);
    }
    sort(sumArray.begin(), sumArray.end(), [](const pair<long long, long long>& a, pair<long long, long long>& b) {
        return a.second > b.second; // Compare based on .second (descending)
    });

    // for(auto p: sumArray) cout<<p.first<<" "<<p.second<<endl;

    long long ans = 0;
    for(long long i = 0; i < n; i++)
    {
        ans += sumArray[i].first + ((n-i-1)*m)*sumArray[i].second;
    }

    cout<<ans<<endl;
}

int main()
{
    CODE
    long long testCases;
    cin>>testCases;
    while(testCases--)
    {
        solve();
    }
}

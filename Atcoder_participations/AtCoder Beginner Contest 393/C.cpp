#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n; 
    cin>>n;
    vector<pair<int, int>> p (n + 1, {0, 0});
    for(int i = 1; i <= n ; i++) cin>>p[i].first;
    for(int i = 1; i <= n ; i++) cin>>p[i].second;

    vector<pair<int, int>> pCopy = p;

    sort(p.begin(), p.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    for(int i = 1; i <= n; i++)
    {
        cout<<pCopy[p[i].first].second<<" ";
    }
}
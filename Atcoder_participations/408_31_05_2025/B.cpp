#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    int temp = 0;
    set<int> ans;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        ans.insert(temp);
    }
    cout<<ans.size()<<endl;
    for(auto it: ans) cout<<it<<" ";
}

int main()
{
    solve();
    return 0;
}


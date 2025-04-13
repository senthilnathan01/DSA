#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fast
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<vector<int>> grid(n, vector<int>(n));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++) cin>>grid[i][j];
        }
        vector<int> ans(2*n + 1, -1);
        set<int> s;
        for(int i = 1; i <= 2*n; i++)
        {
            s.insert(i);
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                ans[i+j+2] = grid[i][j];
                s.erase(grid[i][j]);
            }
        }
        int num;
        for(int it: s) num = it;
        for(int i = 1; i <= 2*n; i++)
        {
            if(ans[i] == -1) cout<<num<<" ";
            else cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
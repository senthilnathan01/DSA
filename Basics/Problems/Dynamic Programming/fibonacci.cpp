#include<bits/stdc++.h>
using namespace std;

// Top Down (Memoization)

int f(int n, vector<int> &dp)
{
    if(n<=1) return n;

    if(dp[n] != -1) return dp[n];

    return dp[n] = f(n-1, dp) + f(n-2, dp);
}


int main()
{
    int n; cin>>n;
    vector<int> dp(n+1, -1);
    cout<<f(n, dp);
    return 0;
}

// Bottom Up (Tabulation)
// Lesser Space Complexity
int main()
{
    int n; cin>>n;
    int prev2 = 0;
    int prev = 1;
    for(int i = 2; i <= n; i++)
    {
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout<<prev;
    return 0;
}


#include<bits/stdc++.h>

using namespace std;

double solve(double n, double m)
{
    double ans = 1;
    for(int i = 1; i <= m; i++)
    {
        ans += pow(n, i);
        if(ans > 1e9) return -1;
    }
    return ans;
}
int main()
{
    double n, m; cin>> n >> m;
    long long ans = solve(n, m);
    if(ans == -1) cout << "inf" << endl;
    else cout << ans << endl;
    return 0;
}

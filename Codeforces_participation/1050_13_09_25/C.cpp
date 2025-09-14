#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

using ll = long long;

void solve() 
{
    int n, m; cin>>n>>m;
    vector<int> a(n+1), b(n+1);
    a[0] = 0, b[0] = 0;
    for(int i = 1; i <= n; i++) cin>>a[i]>>b[i];

    int score = 0;
    int i = 0;
    while(i < n){
        int j = i;
        while(j+1<=n && ((a[j]-b[j]%2 == (a[j+1]-b[j+1])%2))) j++;

        if(i<j){
            score += a[j] - a[i];
            i=j;
            continue;
        }

        int dt =  a[i+1] - a[i];
        int dpos = abs(b[i+1]-b[i]);

        int extrat = dt - dpos;
        score += dpos + (extrat -(extrat%2));
        i++;
    }
    score += (m-a[n]);
    cout<<score<<endl;
}

int main() {
    fast
    int t; cin>>t;
    while (t--) solve();
    return 0;
}

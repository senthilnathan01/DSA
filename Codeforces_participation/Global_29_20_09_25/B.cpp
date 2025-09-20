#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> ans(2*n+1, 0);
    int f = 1;
    
    for(int num = n; num>=1; num--){
        while(ans[f]!=0) f++;
        int p = f;
        int q = -1;
        for(int m=1;;m++){
            int q_ = p + m*num;
            if(q_ > 2*n) break;
            if(ans[q_]==0){
                q = q_;
                break;
            }
        }
        ans[p] = ans[q] = num;
    }
    for(int i = 1; i <= 2*n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
	int t; cin>>t;
	while(t--) solve();
	return 0;
}

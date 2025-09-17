#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n), pos(n+1);
    for(int i = 0; i < n; i++){
        cin>>a[i];
        pos[a[i]] = i;
    }
    
    int l = 0, r = n-1;
    for(int q = 1; q <=n; q++){
        int curr = pos[q];
        if(curr==l) l++;
        else if(curr == r) r--;
        else{cout<<"NO"<<endl; return;}
    }
    cout<<"YES"<<endl;
}

int main() {
	int t; cin>>t;
	while(t--)solve();
	return 0;
}

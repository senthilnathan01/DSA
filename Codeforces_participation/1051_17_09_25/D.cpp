#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

struct FenwickTree{
    vector<int> bit;
    int size;
    
    FenwickTree(int sz) : size(sz), bit(sz, 0) {}
    
    void update(int idx, int d){
        for(; idx < size; idx |= (idx + 1)){
            if((bit[idx]+= d) >= MOD) bit[idx] -= MOD;
        }
    }
    
    int query(int idx){
        if(idx < 0) return 0;
        int sum = 0;
        for(; idx >=0; idx = (idx & (idx + 1)) -1){
            if((sum += bit[idx]) >= MOD) sum -= MOD;
        }
        return sum;
    }
};

vector<FenwickTree> colBit, rowBit;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    
    int sz = n+1;
    colBit.assign(sz, FenwickTree(sz));
    rowBit.assign(sz, FenwickTree(sz));
    
    ll tot = 1;
    colBit[0].update(0, 1);
    rowBit[0].update(0, 1);
    
    for(int val: a){
        vector<int> updates1(sz), updates2(sz);
        for(int j = 0; j < sz; j++) updates1[j] = colBit[j].query(val);
        for(int i = val + 1; i < sz; i++) updates2[i] = rowBit[i].query(val);
        
        for(int j = 0; j < sz; j++){
            if(updates1[j]>0){
                if((tot += updates1[j]) >= MOD) tot -= MOD;
                colBit[j].update(val, updates1[j]);
                rowBit[val].update(j, updates1[j]);
            }
        }
        
        for(int i = val + 1; i < sz; i++){
            if(updates2[i] >0){
                if((tot += updates2[i]) >= MOD) tot -= MOD;
                colBit[val].update(i, updates2[i]);
                rowBit[i].update(val, updates2[i]);
            }
        }
    }
    cout<<tot<<endl;
}

int main() {
	int t; cin>>t;
	while(t--)solve();
	return 0;
}

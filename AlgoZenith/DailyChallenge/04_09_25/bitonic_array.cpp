#include<bits/stdc++.h>
using namespace std;

int bs(vector<int> &arr, int target){
    int l = 0, h = arr.size() -1;
    while(l <= h){
        int m = l + (h-l)/2;
        if(arr[m]==target) return m;
        else if(arr[m]<target)l=m+1;
        else h = m-1;
    }
    return -1;
}

void solve(){
    int n, q; cin>>n>>q;
    vector<int> a(n);
    int max_idx = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(a[max_idx]<a[i]) max_idx = i;
    }

    vector<int> a_1(a.begin(), a.begin() + max_idx);
    vector<int> a_2(a.begin() + max_idx, a.end());
    sort(a_2.begin(), a_2.end());
    // new 0 .... n-1-max_idx
    // t1 -> n-1-max_idx .... 0
    // t2 -> n-1....max_idx
    // new = (n-1) - old
    int query;
    vector<vector<int>> ans;
    while(q--){
        cin>>query;
        int first = bs(a_1, query);
        int second = bs(a_2, query);
        vector<int> subAns;
        if(first != -1) subAns.push_back(first+1);
        if(second != -1){
            second = n-1 - second + 1;
            subAns.push_back(second);
        }
        if(subAns.empty()) ans.push_back({-1});
        else ans.push_back(subAns);
    }
    for(auto vec: ans){
        for(auto num: vec) cout<<num<<" ";
        cout<<endl;
    }
}

int main(){
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

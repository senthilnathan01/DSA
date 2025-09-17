#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n; cin>>n;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    
    for(int i = 0; i < n-1; i++){
        int u, v, x, y;
        cin>>u>>v>>x>>y;
        if(x>y){
            adj[v].push_back(u);
            indegree[u]++;
        }
        else{
            adj[u].push_back(v);
            indegree[v]++;
        }
    }
    
    queue<int> q;
    for(int i = 1; i <=n; i++) if(indegree[i]==0) q.push(i);
    
    vector<int> topo;
    topo.reserve(n);
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        topo.push_back(curr);
        
        for(int it: adj[curr]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    
    vector<int> ans(n+1);
    for(int i = 0; i < n; i++) ans[topo[i]] = i+1;
    for(int i = 1; i <=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int main() {
	int t; cin>>t;
	while(t--)solve();
	return 0;
}

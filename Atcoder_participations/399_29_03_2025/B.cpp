#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> p(n);
    priority_queue <pair<int, int>> pq;
    for(int i = 0; i<n; i++){
        cin>>p[i];
        pq.push({p[i], i});
    }

    int r = 1;
    int k = 0;
    vector<int> ans (n, 0);
    int max = pq.top().first;
    int index = pq.top().second;
    ans[index] = r;
    pq.pop();
    while(!pq.empty())
    {
        k++;
        index = pq.top().second;
        if(max != pq.top().first){
            r += k;
            k = 0;
        }
        max = pq.top().first;
        ans[index] = r;
        pq.pop();
    }
    for(int i = 0; i < n; i++) cout<<ans[i]<<"\n";
    return 0;
}

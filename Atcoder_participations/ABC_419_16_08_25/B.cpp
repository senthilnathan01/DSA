#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int q; cin>>q;
    int temp;
    int x;
    while(q--)
    {
        cin>>temp;
        if(temp==1)
        {
            cin>>x;
            pq.push(x);
        }
        else 
        {
            cout<<pq.top()<<'\n';
            pq.pop();
        }
    }
    return 0;
}
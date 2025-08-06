#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> arr(n);
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
            pq.push(arr[i]);
        }

        int min_sum = INT_MAX;
        for(int i = 0; i < n-1; i++)
        {
            min_sum = min(min_sum, arr[i] + arr[i+1]/2);
        }
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        min_sum = min(min_sum, a + b);
        cout<<min_sum<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin>>n;
    // rem = 1, go with 2. last one 3
    // rem = 2, go with 2. 
    // rem = 3, go with 2, last one 3
    // rem = 0, go with 2
    int rem = n%4;
    if(rem==1){
        if(n==1){
            cout<<200<<endl;
            return;
        }
        else{
            cout<<200*(n/2) + 100<<endl;
            return; 
        }
    }
    else if(rem==2){
        cout<<200*(n/2)<<endl;
        return;
    }
    else if(rem==3){
        if(n==3){
            cout<<300<<endl;
            return;
        }
        else{
            cout<<200*(n/2) + 100<<endl;
            return; 
        }
    }
    else{
        cout<<200*(n/2)<<endl;
        return;
    }
}

int main()
{
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

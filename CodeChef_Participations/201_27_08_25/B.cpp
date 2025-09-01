#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int n; cin>>n;
    string s; cin>>s;

    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '1'){
            int j = i;
            int count = 0;
            while (j < n && s[j] == '1') {
                count++;
                j++;
            }

            if (count < 3) {
                possible = false;
                break;
            }

            i = j - 1;
        }
    }
    return possible;
}

int main()
{
    int t; cin>>t;
    while(t--){
        if(solve()) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
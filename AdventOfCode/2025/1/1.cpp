#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int lines = 4777;
    string temp;
    int pos = 50;
    int ans = 0;
    while(lines--){
        cin>>temp;
        char d = temp[0];
        int jump = stoi(temp.substr(1, temp.length()-1));
        if(d =='L'){
            pos = (pos + 100 - jump)%100;
        }
        else{
            pos = (pos+jump)%100;
        }
        if(pos==0) ans++;
    }
    cout<<ans;
    return 0;
}

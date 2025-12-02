#include <bits/stdc++.h>
using namespace std;

// Brute Force
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int lines = 4777;
    string temp;
    int dial = 50;
    int ans = 0;
    while(lines--){
        cin>>temp;
        char d = temp[0];
        int jump = stoi(temp.substr(1, temp.length()-1));
        if(d=='L'){
            while(jump--){
                dial--;
                if(dial==0) ans++;
                if(dial<0) dial = 99;
            }
        }
        else{
            while(jump--){
                dial++;
                if(dial==100){
                    ans++;
                    dial = 0;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

bool isInvalid(string i){
    if(i.length()&1) return false;
    string num1 = i.substr(0, i.length()/2);
    string num2 = i.substr(i.length()/2, i.length()/2);
    return (num1==num2);
}

bool isInvalidPart2(string s){
    int totLen = s.length();
    for(int pLen = 1; pLen <=totLen/2; pLen++){
        if(totLen % pLen != 0) continue;
        bool isPattern = true;
        for(int i = pLen; i < totLen; i++){
            if(s[i]!=s[i%pLen]){
                isPattern = false;
                break;
            }
        }
        if(isPattern) return true;
    }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string inputLine;
    cin>>inputLine;
    long long ans = 0;
    long long ans2 = 0;
    
    stringstream ss(inputLine);
    string token;
    while(getline(ss, token, ',')){
        stringstream st(token);
        string num;
        vector<long long> nums;
        while(getline(st, num, '-')){
            nums.push_back(stoll(num));
        }
        for(long long i = nums[0]; i <=nums[1]; i++){
            if(isInvalid(to_string(i))) ans += i; 
            if(isInvalidPart2(to_string(i))) ans2 += i;
        }
    }
    cout<<ans<<endl;
    cout<<ans2;

    return 0;
}

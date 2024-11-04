#include<iostream>
#include<algorithm>

using namespace std;

string BinaryToDecimal(int n)
{
    string ans = "";
    while(n)
    {
        ans += to_string(n%2);
        n/=2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout<<BinaryToDecimal(13);
}

// OUTPUT:
// 1101

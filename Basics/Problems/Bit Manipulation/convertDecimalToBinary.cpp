#include<iostream>
#include<algorithm>

using namespace std;

// TC = O(log2N)
// SC = O(log2N)

string DecimalToBinary(int n)
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
    cout<<DecimalToBinary(13);
}

// OUTPUT:
// 1101

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

// TC = O(N)
// SC = O(1)

int BinaryToDecimal(string s)
{
    int ans = 0;
    int length = s.size();
    int twoPower = 1;
    for(int i = length -1; i>=0; i--)
    {
        if(s[i]=='1')  ans += twoPower;
        twoPower*=2;
    }

    return ans;
}

int main()
{
    cout<<BinaryToDecimal("1101");
}


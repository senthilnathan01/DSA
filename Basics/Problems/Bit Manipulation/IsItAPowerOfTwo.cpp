#include<iostream>

using namespace std;

int main()
{
    int n = 16;
    if(n==0) cout<<"No";
    else if(((n)&(n-1))==0) cout<<"Yes";
    else cout<<"No";
}

// OUTPUT:
// Yes

// Explanation
// 16 -> 1000 
// 15 -> 0111

// 16 & 15 = 0000 = 0
// Power of 2

// ----

// 15 -> 0111
// 14 -> 0110

// 15 & 14 = 0110 != 0 
// Not a power of 2

// -16 = 110000


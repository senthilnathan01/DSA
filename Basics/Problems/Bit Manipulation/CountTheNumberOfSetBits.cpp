#include<iostream>

using namespace std;

int main()
{
    int n = 15;

    // Approach 1:
    // Everytime we encounter a 1 increase the count
    // TC = O(N)
    int count = 0;
    while(n>1)
    {
        count += n&1;
        n = n>>1;
    }
    if(n==1) count += 1;
    cout<<count<<endl;

    // Approach 2:
    // Keep clearing the rightmost and increase the count by 1
    // TC = O(number of set bits)
    n = 15;
    count = 0;

    while(n)
    {
        n = ((n)&(n-1));
        count += 1;
    }
    cout<<count;
}

// OUTPUT:
// 4
// 4
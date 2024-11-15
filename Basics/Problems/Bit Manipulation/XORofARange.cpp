#include<iostream>

using namespace std;

/*
PROBLEM:
You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].
*/

// Approach:

/*
We know that XOR of numbers from 1 to N is given by:
if(n%4==1) XOR = 1;
else if(n%4==2) XOR = n+1;
else if(n%4==3) XOR = 0;
else XOR = n;

Thus the answer for XOR(l, r) = XOR(1, l)^XOR(1, r)
*/

int XOR(int n)
{
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%4==3) return 0;
    else return n;
}

int findXOR(int l, int r) {
    return XOR(l-1)^XOR(r);
}

int main()
{
    int l = 4;
    int r = 7;
    cout<<findXOR(l, r);
}

// OUTPUT:
// 0




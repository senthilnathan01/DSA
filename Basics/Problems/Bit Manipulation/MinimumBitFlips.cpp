#include<iostream>

using namespace std;
/*
PROBLEM:
A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. 
We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.
*/

int minimumBitFips(int start, int goal)
{
    int num = start^goal;
    int count=0;
    while(num)
    {
        num = (num&(num-1));
        count++;
    }
    return count;
}

int main()
{
    int start = 7;
    int goal = 10;
    cout<<minimumBitFips(start, goal);
}

// OUTPUT:
// 3





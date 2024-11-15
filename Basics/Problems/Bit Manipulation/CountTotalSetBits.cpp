#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// Approach:

/*
In 4 we have 2*2^(2-1) + 1= 5 set bits
000
001
010
011
100

In 8 we have 3*2^(3-1) + 1 = 13 set bits
0000
0001
0010
0011
0100
0101
0110
0111
1000
*/

/*
Suppose we are given a number like 1011000 = 2^6 + 2^4 + 2^3 = 88
We need to find the total set bits from 0000001 to 1011000
Which is equal to the total set bits in the groups {0000001 to 0111111} and {1000000 to 1011000}
The first group has 6*2^(6-1) = 6*32 = 192 total set bits

The second group is divided into {1000000 to 1001111} and {1010000 to 1011000}
The first group here has total set bits = 4*2^(4-1) + 2^4(For the one in the MSB) = 48

The second group is further divided into {1010000 to 1010111} and {1011000}
The first group here has total set bits = 3*2^(3-1) + 2*2^3 = 12 + 16 = 28 

The second group has  3

Total set bits = 192 + 48 + 28 + 3 = 271 = {6*2^(6-1)} + {4*2^(4-1) + 2^4} + {3*2^(3-1) + 2*2^3} + {Number of set bits in n}

We observe a general formula for this.

Thus given a number decompose it to powers of two do just apply the formula.
*/

int main()
{
    int number = 88;
    vector<int> positions;
    int count = 0;
    while(number)
    {
        if(((number)&1)==1) positions.push_back(count);
        count += 1;
        number = number>>1;
    }
    int totalSetBits = 0;
    int setbits = positions.size();

    totalSetBits += setbits;
    setbits--;

    for(int num: positions)
    {
        totalSetBits += (setbits*pow(2,num) + num*pow(2, num-1));
        setbits--;
    }
    cout<<totalSetBits;
}

// OUTPUT:
// 271







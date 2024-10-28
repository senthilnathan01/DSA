#include<iostream>
#include <climits> 

using namespace std;

/*
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").

Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity is neither present.

Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. 
If no digits were read, then the result is 0.

Rounding: If the integer is out of the 32-bit signed integer range [-2^(31), 2^(31) - 1], then round the integer to remain in the range. 
Specifically, integers less than -2^(31) should be rounded to -2^(31), and integers greater than 2^(31) - 1 should be rounded to 2^(31) - 1.

Return the integer as the final result.
*/

int myAtoi(string s) {
    int i = 0;
    long ans = 0;
    int length = s.size();
    int sign = 1;

    while(i< length && s[i]==' ') i++;
    if(s[i]=='-') 
    {
        sign = -1; 
        i++;
    }
    else if(s[i]=='+') i++;

    while(i<length)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            ans = ans*10 + (s[i]-'0');
            if(ans>=INT_MAX && sign == 1) return INT_MAX;
            else if(ans > INT_MAX && sign == -1) return INT_MIN;
            i++;
        }
        else return ans*sign;
    }
    return ans*sign;    
}

int main()
{
    cout<<myAtoi("   90")<<endl;
    cout<<myAtoi("  -819")<<endl;
    cout<<myAtoi("  ")<<endl;
    cout<<myAtoi("apple")<<endl;
}

// OUTPUT:
// 90
// -819
// 0
// 0
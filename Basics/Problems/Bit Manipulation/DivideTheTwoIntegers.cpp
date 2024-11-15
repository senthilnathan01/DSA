#include<iostream>
#include<cmath>

using namespace std;

// Divide the number only using binary operators
// Return the truncated value

// TC = (O(log_2 n))^2

int Divide(int dividend, int divisor)
{
    // Edge Case
    if(divisor == 0) return -1;
    if(dividend == divisor) return 1;

    bool sign = true;
    if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = false;

    long long a = abs((long long)dividend);
    long long b = abs((long long)divisor);

    // Edge Case
    if(b==1)
    {
        if(a>INT32_MAX) return sign?INT32_MAX:INT32_MIN;
        else return sign?a:(-a);            
    }

    long long sum = 0;
    while(a>=b)
    {
        int count = 0;
        while(a >= (b<<(count+1))) count++;
        sum += (1<<count);
        a -= (b<<count);
    }

    if(sum >= INT32_MAX && sign) return INT32_MAX;
    else if(sum >= INT32_MAX && sign == false) return INT32_MIN;
    else return (sign?sum:(-sum));
}

int main()
{
    long long dividend = -2147483648;
    long long divisor = -1;
    cout<<Divide(dividend, divisor)<<endl;
}

// OUTPUT:
// 2147483647




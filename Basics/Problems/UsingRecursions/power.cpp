#include<iostream>

using namespace std;

// Normal Approach using Binary Exponentiation

double pow(double x, int n)
{
    double ans = 1.0;
    long long int nn = n;
    if(n<0) nn*=(-1);
    while(nn>0)
    {
        if(nn%2==1)
        {
            ans*=x;
            nn--;
        }
        else
        {
            x*=x;
            nn/=2;
        }
    }
    if(n<0) ans = 1.0/ans;
    return ans;
}

// Using recursion
double Pow(double ans, double x, long n)
{
    if(n==0) return ans;
    if(n%2)
    {
        n--;
        ans = ans*x;
    }
    else
    {
        x = x*x;
        n = n/2;
    }
    return Pow(ans, x, n);
}

double myPow(double x, int n) {
    double ans = 1.0;
    double nn = n;
    if(nn<0) nn*=(-1);
    ans = Pow(ans, x, nn);
    if(n<0) ans = 1.0/ans;
    return ans;
}

int main()
{
    cout<<pow(2.1, 5)<<endl;
}

// OUTPUT:
// 40.841
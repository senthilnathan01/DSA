#include<iostream>

using namespace std;

void swap2numbers(int a, int b)
{
    a = a^b;
    b = a^b;
    cout<<"b= "<<b<<endl;
    a = a^b;
    cout<<"a= "<<a<<endl;
}

int main()
{
    swap2numbers(5, 10);
}

// b= 5
// a= 10

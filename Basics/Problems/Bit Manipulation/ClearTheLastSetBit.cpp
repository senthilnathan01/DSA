#include<iostream>

using namespace std;

int main()
{
    int number = 84;
    
    cout<<((number)&(number-1));
}

// OUTPUT:
// 80

// Explanation:
// 84 -> (10101000) -> (10101000)&(10100111) = (10100000) = 80


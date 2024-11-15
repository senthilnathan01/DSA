#include<iostream>

using namespace std;

int main()
{
    int number = 15;
    int position = 2;
    
    cout<<(number^(1<<position));
}

// OUTPUT:
// 11

// Explanation:
// 15 -> 1111 -> 1111^(100) -> 1011 = 11

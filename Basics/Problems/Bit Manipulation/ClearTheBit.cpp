#include<iostream>

using namespace std;

int main()
{
    int number = 15;
    int position = 0;

    cout<<((number)&(~(1<<position)));
}

// OUTPUT:
// 14

// Explanation
// 15 -> 1111 -> 1110 -> 14

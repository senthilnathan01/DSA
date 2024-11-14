#include<iostream>

using namespace std;


int main()
{
    int number = 9;
    int position = 2;
    cout<<(number|(1<<position));
}

// OUTPUT:
// 13

// Explanation:
// 9 -> 1001 -> 1101 = 13
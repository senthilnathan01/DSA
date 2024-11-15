#include<iostream>

using namespace std;

int main()
{
    int number = 6;
    int temp = number;
    int position = 0;

    while(temp&1)
    {
        position++;
        temp = temp>>1;
    }
    cout<<((number)|(1<<position));
}

// OUTPUT:
// 7

// 6 = 110 -> 111 = 7




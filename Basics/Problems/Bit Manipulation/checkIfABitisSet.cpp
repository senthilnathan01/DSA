#include<iostream>

using namespace std;

// Approach 1:
// Using left shift operator
void checkIfTheBitIsSet1(int number, int position)
{
    if(number & (1<<position)!=0) cout<<"Set"<<endl;
    else cout<<"Not Set"<<endl;
}

// Approach 2:
// Using Right Shift operator
void checkIfTheBitIsSet2(int number, int position)
{
    if((number>>position)&1 !=0) cout<<"Set"<<endl;
    else cout<<"Not Set"<<endl;
}

int main()
{
    checkIfTheBitIsSet1(13, 2);
    checkIfTheBitIsSet2(13, 2);
}

// OUTPUT:
// Set
// Set

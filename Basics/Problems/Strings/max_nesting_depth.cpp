#include<iostream>

using namespace std;

/*
Given a valid parentheses string s, return the nesting depth of s. 
The nesting depth is the maximum number of nested parentheses.
*/

int maxDepth(string s) {
    int current_depth=0;
    int max_depth = 0;
    for(char c:s)
    {
        if(c=='(') current_depth++; //Increase the depth if '(' is found
        else if(c==')') current_depth--; //Decrease the depth if ')' is found   
        if(current_depth>max_depth) max_depth = current_depth; // Update the max depth info
    }
    return max_depth;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    cout<<maxDepth(s);
}

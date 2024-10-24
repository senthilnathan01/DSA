#include<iostream>

using namespace std;

/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
*/

bool rotateString(string s, string goal) {
    if(s.size()!=goal.size()) return false; // Strings must have the same length

    goal += goal; // Concatenate the goal string with itself.
    int n = s.size();
    // Check if the original string is a substring of the concatenated goal.
    for(int i = 0; i < n; i++)
    {
        if(goal.substr(i, n) == s) return true;
    }
    return false;
}


int main()
{
    string s = "bcdea";
    string goal = "abcde";

    cout<<rotateString(s, goal)<<endl;
}

// OUTPUT:
// 1
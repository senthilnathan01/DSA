#include<iostream>
#include<vector>
#include<set>

using namespace std;

string solve(vector<int> &a)
{
    if(a[0]==a[1]*a[2]) return "Yes";
    if(a[1]==a[0]*a[2]) return "Yes";
    if(a[2]==a[0]*a[1]) return "Yes";
    return "No";
}

int main()
{
    int n, m;
    vector<int> inputArr (m, 0);
    set<int> mySet;
    for(int i = 1; i < n; i++) 
    vector<int> ans;
    return 0;
}
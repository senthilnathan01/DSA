#include<iostream>
#include<cmath>
using namespace std;

/*
Given an integer n representing number of vertices. 
Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.
*/

class Solution {
  public:
    long long count(int n) {
        // your code here
        if(n<=2) return n;
        long long edges  = n*(n-1)/2;
        long long count = pow(2, edges);
        return count;
    }
};

int main()
{
    Solution obj;
    cout<<obj.count(5);

    return 0;
}

// OUTPUT:
// 1024
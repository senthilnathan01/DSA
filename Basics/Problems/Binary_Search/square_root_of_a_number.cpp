#include<iostream>
#include<cmath>

using namespace std;

/*
Given an integer n, find the square root of n. 
If n is not a perfect square, then return the floor value.
*/

// Using binary search
long long int floorSqrt(long long int n){
    // Best case
    if(n == 0 || n == 1) return n;
    long long int low = 1, high = n, ans;

    // Binary search to find the square root of the number
    while(low<=high)
    {
        long long mid = (low+high)/2;
        // Check if mid = sqrt(n)
        if(mid*mid==n) return mid;
        // Check the right part
        if(mid*mid<n)
        {
            low = mid + 1;
            ans = mid;
        }
        else high = mid - 1; // Check the left part
    }
    return ans;
}


int main() {
    cout<<floorSqrt(3)<<endl;
    cout<<floorSqrt(36)<<endl;
    return 0;
}

// OUTPUT:
// 1
// 6


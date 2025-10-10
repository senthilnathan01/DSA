/*
Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

LINK: https://leetcode.com/problems/number-of-1-bits/description/
*/

// Approach 1
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        int digits = static_cast<int>(floor(log2(n))) + 1;
        for(int i = digits-1; i >= 0; i--){
            if(n&(1<<i)) cnt++;
        }
        return cnt;
    }
};

// Approach 2
// Just iterate till 32 bits
// No need to calculate digits
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        for(int i = 31; i >= 0; i--){
            if(n&(1<<i)) cnt++;
        }
        return cnt;
    }
};

// Learn a new algo called Brian Kernighan’s Algorithm for counting set bits (Hamming Weight)
// n&(n-1) removes exactly one 1 bit each time.
class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n){
            n&=(n-1);
            cnt++;
        }
        return cnt;
    }
};

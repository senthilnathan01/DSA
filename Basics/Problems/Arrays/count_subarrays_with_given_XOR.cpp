/*
Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k

LINK: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1 
*/
// Naive Approach - O(N^2)
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            int pref = 0;
            for(int j = i; j < n; j++){
                pref^=arr[j];
                if(pref==k) ans++;
            }
        }
        return ans;
    }
};

// Optimised - O(N)
// Let
// XOR[0...i-1] = A
// XOR[i...j] = B
// XOR[0...j] = C
// B = k
// A^k=C
// A=C^k
// By the time we are trying to compute C, we would have already computed A
// So, it suffices to check if there is some A for every C such that k exists where A = C^k
// For some C many such A might exist, that's why increment the answer by those many times of A
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> freq;
        int ans = 0;
        freq[0]=1; //empty subarray
        int pref = 0;
        for(int num: arr){
            pref^=num;
            int target = pref^k;
            if(freq.find(target)!=freq.end()) ans += freq[target];
            freq[pref]++;
        }
        return ans;
    }
};

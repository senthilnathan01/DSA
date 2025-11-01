/*
Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10 } and a target value n. 
Find the minimum number of coins and/or notes needed to make the change for Rs n. 

LINK: https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1
*/
class Solution {
  public:
    int findMin(int n) {
        // code here
        int rem = n;
        int ans = 0;
        while(rem > 0){
            if(rem>=10){
                ans += rem / 10;
                rem %= 10;
            }
            else if(rem >= 5){
                ans += rem / 5;
                rem %= 5;
            }
            else if(rem >= 2){
                ans += rem /2;
                rem %= 2;
            }
            else if(rem >=1){
                ans += rem;
                break;
            }
        }
        return ans;
    }
};

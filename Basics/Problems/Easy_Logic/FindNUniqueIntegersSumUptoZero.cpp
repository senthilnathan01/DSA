/*
Given an integer n, return any array containing n unique integers such that they add up to 0.

  LINK: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/?envType=problem-list-v2&envId=55vr69d7
*/

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n&1){
            for(int i = 1; i <= (n-1)/2; i++) ans.push_back(i);
            for(int i = 1; i <=(n-1)/2; i++) ans.push_back(i*-1);   
            ans.push_back(0);         
        }
        else{
            for(int i = 1; i <= n/2; i++) ans.push_back(i);
            for(int i = 1; i <=n/2; i++) ans.push_back(i*-1);
        }
        return ans;
    }
};

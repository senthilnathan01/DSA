/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

LINK: https://leetcode.com/problems/sequential-digits/description/
*/  

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string base = "123456789";
        vector<int> ans;
        int minLen = to_string(low).size();
        int maxLen = to_string(high).size();
        int num;
        for(int len = minLen; len <= maxLen; len++){
            for(int pos = 0; pos + len <=9; pos++){
                num = stoi(base.substr(pos, len));
                if(num>=low && num<=high) ans.push_back(num);
            }
        }
        return ans;
    }
};

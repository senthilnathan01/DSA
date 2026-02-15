/*
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

LINK: https://leetcode.com/problems/search-suggestions-system/description/
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

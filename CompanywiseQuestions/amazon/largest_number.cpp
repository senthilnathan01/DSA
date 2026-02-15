/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

LINK: https://leetcode.com/problems/largest-number/description/
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(const int &num: nums) arr.push_back(to_string(num));
        sort(arr.begin(), arr.end(), [](const string& a, const string& b){
            return a + b > b + a;
        });

        //  Edge case: we do want to return numbers like "00" ("0"+"0")
        if(arr[0]=="0") return "0";

        string ans;
        for(const string& word: arr) ans += word;
        return ans;
    }
};

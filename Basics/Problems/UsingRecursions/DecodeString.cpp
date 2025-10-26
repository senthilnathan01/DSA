/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

LINK: https://leetcode.com/problems/decode-string/description/?envType=problem-list-v2&envId=55vr69d7&
*/
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }

    string decode(const string &s, int &i){
        string res = "";
        int times = 0;
        while(i<s.size()){
            char ch = s[i];
            if(isdigit(ch)){
                times = times*10 + (ch-'0');
                i++;
            }
            else if(ch == '['){
                i++;
                string inner = decode(s, i);
                for(int k = 0; k < times; k++) res += inner;
                times = 0;
            }
            else if(ch==']'){
                i++;
                return res;
            }
            else{
                res += ch;
                i++;
            }
        }
        return res;
    }
};

/*
You are given a 0-indexed binary string s which represents the types of buildings along a street where:

s[i] = '0' denotes that the ith building is an office and
s[i] = '1' denotes that the ith building is a restaurant.
As a city official, you would like to select 3 buildings for random inspection. However, to ensure variety, no two consecutive buildings out of the selected buildings can be of the same type.

For example, given s = "001101", we cannot select the 1st, 3rd, and 5th buildings as that would form "011" which is not allowed due to having two consecutive buildings of the same type.
Return the number of valid ways to select 3 buildings.

LINK: https://leetcode.com/problems/number-of-ways-to-select-buildings/description/
*/
class Solution {
public:
    long long numberOfWays(string s) {
        long long total0 = 0, total1 = 0;

        for(char c : s) {
            if(c == '0') total0++;
            else total1++;
        }

        long long prefix0 = 0, prefix1 = 0;
        long long ans = 0;

        for(char c : s) {
            if(c == '0') {
                ans += prefix1 * (total1 - prefix1);
                prefix0++;
            } else {
                ans += prefix0 * (total0 - prefix0);
                prefix1++;
            }
        }

        return ans;
    }
};

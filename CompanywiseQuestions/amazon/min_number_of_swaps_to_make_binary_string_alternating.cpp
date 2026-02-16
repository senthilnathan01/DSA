/*
Given a binary string s, return the minimum number of character swaps to make it alternating, or -1 if it is impossible.

The string is called alternating if no two adjacent characters are equal. For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

Any two characters may be swapped, even if they are not adjacent.

LINK: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/description/
*/

class Solution {
public:
    int countSwaps(string s, char startChar){
        int mismatches = 0;
        for(int i = 0; i < s.size(); i++){
            char expected = (i%2==0) ? startChar : (startChar == '0' ? '1':'0');
            if(s[i]!=expected) mismatches++;
        }
        return mismatches/2;
    }

    int minSwaps(string s) {
        int num_ones = 0;
        int num_zeroes = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i]=='0') num_zeroes++;
            else num_ones++;
        }

        if(abs(num_zeroes - num_ones)>1) return -1;

        if(num_zeroes > num_ones) return countSwaps(s, '0');
        else if(num_zeroes < num_ones) return countSwaps(s, '1');
        else return min(countSwaps(s, '0'), countSwaps(s, '1'));
    }
};

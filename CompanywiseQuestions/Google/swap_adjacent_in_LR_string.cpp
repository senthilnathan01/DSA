/*
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", a move consists of either replacing one occurrence of "XL" with "LX", 
  or replacing one occurrence of "RX" with "XR". Given the starting string start and the ending string result, 
  return True if and only if there exists a sequence of moves to transform start to result.

LINK: https://leetcode.com/problems/swap-adjacent-in-lr-string/description/
*/
class Solution {
public:
    bool canTransform(string start, string result) {
        if(start.length()!=result.length()) return false;

        // u can check for frequency of X, R, L in start and result
        // and return false if there is a mismatch
        // but we don't really need to do that here with this approach

        int n = start.length();
        size_t p1 = 0, p2 = 0;
        while(p1<n && p2<n){
            while(p1<n && start[p1]=='X')p1++;
            while(p2<n && result[p2]=='X')p2++;

            if(p1==n || p2==n) break;
            if(start[p1]!=result[p2]) return false;

            if(start[p1]=='L' && p2>p1) return false;
            if(start[p1]=='R' && p2<p1) return false;
            p1++;
            p2++;
        }
        while(p1<n && start[p1]=='X') p1++;
        while(p2<n && result[p2]=='X')p2++;
        return p1==n && p2==n;
    }
};

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Leetcode Link: https://leetcode.com/problems/longest-repeating-character-replacement/description/
*/

// Some explanations to the code:
/*
maxFreq can get smaller as sliding window shrinks. Provided code does not account for that. You might think this.

I had this question too, but upon closer inspection, I think that it is not necessary to update maxFreq when your window shrinks. 
Even though technically, the variable will hold the "wrong" value, there is no issue, because your max sliding window length was 
calculated with that specific max frequency, and the only way to find a bigger sliding window is to increase maxFreq, which will 
only occur if there is a character in the map that has a greater frequency than maxFreq. So even if you technically have an 
"invalid sliding window" at some points (from not updating maxFreq properly), it will not lead to an incorrect solution.

The key is this: With a "global" maxFreq, the solution might be more efficient because it might do less shrinking.
*/

// The most optimal solution:
class Solution {
public:
    int characterReplacement(std::string s, int k) {
        unordered_map<char, int> count;
        int res = 0;

        int l = 0, maxf = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};

// The normal solution (may not be most optimal)
class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int res = 0;
        unordered_set<char> charSet(s.begin(), s.end());

        for (char c : charSet) {
            int count = 0, l = 0;
            for (int r = 0; r < s.size(); r++) {
                if (s[r] == c) {
                    count++;
                }

                while ((r - l + 1) - count > k) {
                    if (s[l] == c) {
                        count--;
                    }
                    l++;
                }

                res = std::max(res, r - l + 1);
            }
        }
        return res;
    }
};

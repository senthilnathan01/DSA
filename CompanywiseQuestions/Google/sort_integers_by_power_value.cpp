/*
The power of an integer x is defined as the number of steps needed to transform x into 1 using the following steps:

if x is even then x = x / 2
if x is odd then x = 3 * x + 1
For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers lo, hi and k. The task is to sort all integers in the interval [lo, hi] by the power value in ascending order, if two or more integers have the same power value sort them by ascending order.

Return the kth integer in the range [lo, hi] sorted by the power value.

Notice that for any integer x (lo <= x <= hi) it is guaranteed that x will transform into 1 using these steps and that the power of x is will fit in a 32-bit signed integer.

LINK: https://leetcode.com/problems/sort-integers-by-the-power-value/description/
*/
class Solution {
public:
    vector<long long> memo;
    int powerFunc(int num){
        if(num<memo.size() && memo[num]!=-1) return memo[num];
        long long temp = num;
        int cnt = 0;

        while(temp>1){
            if(temp<memo.size() && memo[temp]!=-1) return memo[num]=cnt+memo[temp];
            cnt++;
            if(temp&1) temp = 3*temp+1;
            else temp>>=1;
        }
        return memo[num]=cnt+memo[temp];
    }
    int getKth(int lo, int hi, int k) {
        memo.assign(hi*10+1,-1);
        memo[1] = 0;
        vector<pair<int, int>> vec;
        for(int num = lo; num <= hi; num++) vec.push_back({powerFunc(num), num});
        sort(vec.begin(), vec.end());
        return vec[k-1].second;
    }
};

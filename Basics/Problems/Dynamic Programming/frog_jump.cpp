/*
A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

LeetCode Link: https://leetcode.com/problems/frog-jump/description/
*/

class Solution {
public:
    int binary_search(int low, int high, vector<int> &stones, int toFind) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (stones[mid] < toFind) low = mid + 1;
            else if (stones[mid] > toFind) high = mid - 1;
            else return mid;
        }
        return -1;
    }

    unordered_map<long long, bool> memo;

    bool canLand(int idx, int endIdx, int jump, vector<int> &stones) {
        if (idx == endIdx) return true;
        long long key = ((long long)idx << 32) | jump;
        if (memo.count(key)) return memo[key];

        int res1 = (jump > 1) ? binary_search(idx + 1, endIdx, stones, stones[idx] + jump - 1) : -1;
        int res2 = binary_search(idx + 1, endIdx, stones, stones[idx] + jump);
        int res3 = binary_search(idx + 1, endIdx, stones, stones[idx] + jump + 1);

        if (res1 != -1 && canLand(res1, endIdx, jump - 1, stones)) return memo[key] = true;
        if (res2 != -1 && canLand(res2, endIdx, jump, stones)) return memo[key] = true;
        if (res3 != -1 && canLand(res3, endIdx, jump + 1, stones)) return memo[key] = true;

        return memo[key] = false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();
        return canLand(0, n - 1, 0, stones);
    }
};

// PRO TIP: Get the brute force solution
// Sometimes the optimised and better solutions can be easily found once the initial approach (brute force) is established

/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. 
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

Leetcode Link: https://leetcode.com/problems/koko-eating-bananas/description/
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        int ans = r;

        while(l <= r)
        {
            int k = (l+r)/2;

            long long totalTime = 0;
            for(int p : piles) totalTime += ceil(static_cast<double> (p)/k);

            if(totalTime <=h)
            {
                ans = k;
                r = k - 1;
            }
            else l = k + 1;
        }

        return ans;
    }
};

/*
Given start, end and an array arr of n numbers. At each step, start is multiplied with any 
number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. 
If it is not possible to reach end, then return -1.
*/

class Solution {
    typedef pair<int, int> P;
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        // Base Case
        if(start == end) return 0;
        int mod = 100000;
        queue<P> q;
        q.push({start, 0});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        while(!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            for(auto it: arr)
            {
                int num = (it*node) % mod;
                if(steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;
                    if(num == end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};

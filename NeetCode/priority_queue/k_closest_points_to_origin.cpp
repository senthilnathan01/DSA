/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

LINK: https://leetcode.com/problems/k-closest-points-to-origin/description/
*/

class Solution {
public:
    typedef pair<double, pair<int, int>> P;
    struct cmp{
        bool operator()(P a, P b) const{return a.first < b.first;}
    };
    priority_queue<P, vector<P>, cmp> pq;
    void add(pair<int, int> num, int k){
        double dist = sqrt(num.first*num.first + num.second*num.second);
        if(pq.size()<k) pq.push({dist, num});
        else{
            if(pq.top().first>dist){
                pq.pop();
                pq.push({dist, num});
            }
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(auto vec: points) add({vec[0], vec[1]}, k);
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};

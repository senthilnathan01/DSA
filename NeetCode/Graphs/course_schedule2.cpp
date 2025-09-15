/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. 
If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

LINK: https://leetcode.com/problems/course-schedule-ii/description/
*/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        vector<int> ans;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for(auto &it: prereq){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i<n; i++) if(indegree[i]==0) q.push(i);

        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        return (ans.size()==n) ? ans :  vector<int>();
    }
};

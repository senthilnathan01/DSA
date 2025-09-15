/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
  You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

LINK: https://leetcode.com/problems/course-schedule/description/
*/

// If there is a cycle we won't be able to visit all the nodes
// Used Kahn's algo for topo sort here
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto it: prerequisites){
            int u = it[1]; // check the order
            int v = it[0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) if(indegree[i]==0) q.push(i);

        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();

            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }

        return (cnt == numCourses);
    }
};

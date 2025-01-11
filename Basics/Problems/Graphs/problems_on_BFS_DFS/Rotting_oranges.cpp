#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size(); 

        queue<pair<int, int>> q;
        int time = 0;

        // Stores all the cells with 1
        set<pair<int, int>> s;
        bool freshPresent = false;
        bool rottenPresent = false;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j]==1) s.insert({i, j});
                else if(grid[i][j]==2) q.push({i, j});
            }
        }

        if(!s.empty()) freshPresent = true;
        if(!q.empty()) rottenPresent = true;

        queue<pair<int, int>> q2;
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            
            int x = p.first, y = p.second;

            if(s.count({x-1, y}))
            {
                q2.push({x-1, y});
                s.erase({x-1, y});
            }
            if(s.count({x+1, y}))
            {
                q2.push({x+1, y});
                s.erase({x+1, y});
            }
            if(s.count({x, y+1}))
            {
                q2.push({x, y+1});
                s.erase({x, y+1});
            }
            if(s.count({x, y-1}))
            {
                q2.push({x, y-1});
                s.erase({x, y-1});
            }     
            if(q.empty())
            {
                time++;
                swap(q2, q);
            }
        }
        
        if(!s.empty())
        {
            return -1;
        }
        else return max(0, time-1); 
    }
};

int main()
{
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    // 2 1 1
    // 1 1 0
    // 0 1 1
    Solution obj;
    cout<< obj.orangesRotting(grid);
    return 0;
}

// OUTPUT:
// 4

// Explanation:
// At t = 1
// 2 2 1
// 2 1 0
// 0 1 1

// At t = 2
// 2 2 2
// 2 2 0
// 0 1 1

// At t = 3
// 2 2 2
// 2 2 0
// 0 2 1

// At t = 4
// 2 2 2
// 2 2 0
// 0 2 2
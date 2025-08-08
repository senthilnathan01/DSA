/*
Rat in a maze

Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.

GFG Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
*/

class Solution {
  public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    char numToDir(int dir)
    {
        if(dir==0)
        {
            return 'U';
        }
        else if(dir == 1)
        {
            return 'D';
        }
        else if(dir == 2)
        {
            return 'L';
        }
        else return 'R';
    }
    
    bool isValid(int row, int col, int n, vector<vector<int>> &maze, vector<vector<bool>> &visited)
    {
        return (row >= 0 && row < n && col >= 0 && col < n && maze[row][col] == 1 && visited[row][col]==false);
    }
    
    void backtrack(int row, int col, vector<vector<int>> &maze, vector<vector<bool>> &visited, 
    vector<string> &ans, string &path, int n)
    {
        if(row == n-1 && col == n-1)
        {
            ans.push_back(path);
            return;
        }
        
        for(int dir = 0; dir < 4; dir++)
        {
            int new_r = row + dr[dir], new_c = col + dc[dir];
            if(!isValid(new_r, new_c, n, maze, visited)) continue;
            
            path.push_back(numToDir(dir));
            visited[new_r][new_c] = true;
            
            backtrack(new_r, new_c, maze, visited, ans, path, n);
            
            path.pop_back();
            visited[new_r][new_c] = false;
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> ans;
        string path;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        visited[0][0] = true;
        backtrack(0, 0, maze, visited, ans, path, n);
        sort(ans.begin(), ans.end()); // Lexicogrphical order
        return ans;
    }
};

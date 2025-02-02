#include<iostream>
#include<vector>

using namespace std;

/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        if(rows == 0) return -1;
        int cols = grid[0].size();

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        // Create copy of the grid cuz we shouldn't mess with the given data
        vector<vector<int>> gridCopy = grid;

        
        // Go over the boundary cells
        // First and last row
        for(int j = 0; j < cols; j++)
        {
            dfs({0,j}, gridCopy, dx, dy, rows, cols);
            dfs({rows -1,j}, gridCopy, dx, dy, rows, cols);
        }

        // First and Last Column
        for(int i = 1; i < rows-1; i++)
        {
            dfs({i, 0}, gridCopy, dx, dy, rows, cols);
            dfs({i, cols -1}, gridCopy, dx, dy, rows, cols);
        }

        //Count all the remaning 1's
        int count = 0;
        for(int i = 0; i <rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(gridCopy[i][j] == 1) count++;
            }
        }

        return count;
    }
    
private:
    bool isValidCell(pair<int, int> cell, int rows, int cols)
    {
        int x = cell.first, y = cell.second;
        return 0 <= x && x < rows && 0 <= y && y < cols;
    }

    void dfs(pair<int, int> cell, vector<vector<int>> &grid, int *dx, int *dy, int rows, int cols)
    {
        if(isValidCell(cell, rows, cols) && grid[cell.first][cell.second] == 1)
        {
            grid[cell.first][cell.second] = -1;
            for(int d = 0; d < 4; d++)
            {
                dfs({cell.first + dx[d], cell.second + dy[d]}, grid, dx, dy, rows, cols);
            }
        }
    }

};

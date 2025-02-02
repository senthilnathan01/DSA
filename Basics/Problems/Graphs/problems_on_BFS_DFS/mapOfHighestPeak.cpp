#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
  You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.
*/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int dx[4] = {0, 0, 1, -1}; // Horizontal Movement
        int dy[4] = {1, -1, 0, 0}; // Vertical Movement

        int rows = isWater.size();
        int cols = isWater[0].size();

        // Initialize the height matrix with -1
        vector<vector<int>> cellHeights(rows, vector<int> (cols, -1));

        queue<pair<int,int>> cellQueue;

        // Add all the water cells to the queue and set their height to 0
        for(int x = 0; x < rows; x++)
        {
            for(int y = 0; y < cols; y++)
            {
                if(isWater[x][y])
                {
                    cellQueue.push({x,y});
                    cellHeights[x][y] = 0;
                }
            }
        }

        // Initial height for land cells adjacent to water
        int heightOfNextLayer = 1;

        while(!cellQueue.empty())
        {
            int layerSize = cellQueue.size();

            // Iterate through all cells in the current layer
            for(int i = 0; i < layerSize; i++)
            {
                pair<int, int> currentCell = cellQueue.front();
                cellQueue.pop();

                // Get the neighbouring cells
                for(int d = 0; d < 4; d++)
                {
                    pair<int, int> neighborCell = {currentCell.first + dx[d],
                                                    currentCell.second + dy[d]};

                    // Check if the neighbor is valid and unprocessed
                    if(isValidCell(neighborCell, rows, cols) && 
                        cellHeights[neighborCell.first][neighborCell.second] == -1)
                    {
                        cellHeights[neighborCell.first][neighborCell.second] = 
                            heightOfNextLayer;
                        cellQueue.push(neighborCell);
                    }
                }
            }
            heightOfNextLayer++; 
        }
        return cellHeights;
    }

private:
bool isValidCell(pair<int, int> cell, int rows, int cols)
{
    // Function to check if a cell is within the grid boundaries
    int x = cell.first, y = cell.second;
    return 0 <= x && x < rows && 0 <= y && y < cols;
}
};

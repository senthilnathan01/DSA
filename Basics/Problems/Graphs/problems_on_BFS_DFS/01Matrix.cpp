// This is same as the mapOfHeighestPeak.cpp

/*
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size();

        int dx[4] = {0, 0, 1, -1}; // Horizontal Movement
        int dy[4] = {1, -1, 0, 0}; // Vertical Movement

        // Initialize with -1
        vector<vector<int>> dist(rows, vector<int>(cols, -1));

        queue<pair<int, int>> cellQueue;

        // Add all the cells with 0 in mat to the queue and set their distance to 0
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(mat[i][j] == 0)
                {
                    cellQueue.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        int nearestDist = 1;
        while(!cellQueue.empty())
        {
            int layerSize = cellQueue.size();

            // Iterate through all the cells in the current layer
            for(int i = 0; i < layerSize; i++)
            {
                pair<int, int> cell = cellQueue.front();
                cellQueue.pop();
                for(int d = 0; d < 4; d++)
                {
                    pair<int, int> neighborCell = {cell.first + dx[d], cell.second + dy[d]};

                    // Check if the neighborCell is valid and unprocessed
                    if(isValidCell(neighborCell, rows, cols) &&
                        dist[neighborCell.first][neighborCell.second] == -1)
                    {
                        cellQueue.push({neighborCell.first, neighborCell.second});
                        dist[neighborCell.first][neighborCell.second] = nearestDist;
                    }
                }
            }
            nearestDist++;
        }
        return dist;
    }

private:
    bool isValidCell(pair<int, int> cell, int rows, int cols)
    {
        int x = cell.first, y = cell.second;
        return 0 <=x && x < rows && 0 <= y && y < cols;
    }
};

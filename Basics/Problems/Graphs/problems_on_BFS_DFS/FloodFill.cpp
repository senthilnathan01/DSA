#include<iostream>
#include<vector>
#include<queue>

using namespace std;

/*
You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. 
You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:

Begin with the starting pixel and change its color to color.
Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
The process stops when there are no more adjacent pixels of the original color to update.
Return the modified image after performing the flood fill.
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        // Base Case
        if(image[sr][sc]==color) return image;

        int startColor = image[sr][sc];
        image[sr][sc] = color;

        int rows = image.size();
        int cols = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while(!q.empty())
        {
            int cx = q.front().first, cy = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int x = cx + dx[i], y = cy + dy[i];
                if(x < 0 || x >= rows || y < 0 || y >= cols || image[x][y]==color)  continue;
                if(image[x][y] == startColor)
                {
                    image[x][y] = color;
                    q.push({x, y});
                }
            }
        }

        return image;
    }
};

int main()
{
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    // 1 1 1
    // 1 1 0
    // 1 0 1

    int  sr = 1, sc = 1, color = 2;
    Solution obj;
    vector<vector<int>> ans = obj.floodFill(image, sr, sc, color);
    for(auto vec: ans)
    {   
        for(int num: vec) cout<<num<<" ";
        cout<<endl;
    }
    return 0;
}

// OUTPUT:
// 2 2 2 
// 2 2 0 
// 2 0 1 

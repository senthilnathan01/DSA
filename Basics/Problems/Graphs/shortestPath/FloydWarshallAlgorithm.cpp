/*
The problem is to find the shortest distances between every pair of vertices in a 
given edge-weighted directed graph. The graph is represented as an adjacency matrix. 
mat[i][j] denotes the weight of the edge from i to j. If mat[i][j] = -1, it means there is no edge from i to j.
Note: Modify the distances for every pair in place.
*/

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == -1)
                {
                    mat[i][j] = 1e9;
                }
                if (i == j) mat[i][j] = 0;
            }
        }
        
        for(int via = 0; via < n; via++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    mat[i][j] =  min(mat[i][j], 
                    mat[i][via] + mat[via][j]);
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 1e9) mat[i][j] = -1;
            }
        }
    }
};

/*
You are given a matrix having ‘N’ rows and ‘M’ columns. Each cell of the matrix can only contain three values as given below:

-1 -> It denotes a wall or an obstacle

0  -> It denotes a gate

2^31 - 1 =  2147483647 ( INF ) -> An infinitely large value  denotes the empty room.

For each empty room (denoted by INF), you have to refill it with the distance to its nearest gate. If none of the gates is reachable from an empty room then the value ‘INF’ will remain as it is.
Example
For the matrix [[0,-1],[0,2147483647]] the updated matrix will be [[0,-1],[0,1]].
Note
The distance between two cells having their coordinates (x1,y1) and (x2,y2) are abs(x2-x1) + abs(y2-y1).

LINK: https://www.naukri.com/code360/problems/walls-and-gates_1092887
*/

#include <bits/stdc++.h> 
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j]==0) q.push({i, j});
        }
    }

    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        for(auto [dx, dy]: dirs){
            int nr = r + dx, nc = c + dy;
            if(nr>=0 && nr<n && nc >= 0 && nc<m && a[nr][nc]==INT_MAX){
                a[nr][nc] = a[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    return a;
}


#include<iostream>
#include<vector>
#include<set>

using namespace std;

set<pair<int, int>> getTrailends(vector<vector<int>> locationMat, set<pair<int, int>> currentLocs, int value)
{
    int rows = locationMat.size();
    int cols = locationMat[0].size();
    if(value==9) return currentLocs;
    else
    {
        set<pair<int, int>> nextLocs;
        for(auto pair: currentLocs)
        {
            // Top
            if(pair.first-1 >=0 && locationMat[pair.first-1][pair.second]==value+1) nextLocs.insert({pair.first-1, pair.second});
            // Right
            if(pair.second+1<cols && locationMat[pair.first][pair.second+1]==value+1) nextLocs.insert({pair.first, pair.second+1});
            // Bottom
            if(pair.first+1<rows && locationMat[pair.first+1][pair.second]==value+1) nextLocs.insert({pair.first+1, pair.second});
            // Left
            if(pair.second-1>=0 && locationMat[pair.first][pair.second-1]==value+1) nextLocs.insert({pair.first, pair.second-1});
        }
        if(nextLocs.size()>0) return getTrailends(locationMat, nextLocs, value+1);
        else return {};
    }
}

int main()
{
    int rows = 52, cols = 52;
    vector<vector<int>> locationMat(rows);
    for(int i = 0; i<rows; i++)
    {
        string input;
        cin>>input;
        for(int j = 0; j<cols; j++) locationMat[i].push_back(int(input[j])-48);
    }
    int totScore = 0;
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            //Get a 0
            if(locationMat[i][j]==0)
            {   //Found a 0
                pair<int, int> currentPos = {i, j};
                set<pair<int, int>> currentLocs;
                currentLocs.insert(currentPos);
                set<pair<int, int>> trailEnds = getTrailends(locationMat, currentLocs, 0);
                int score = trailEnds.size();
                totScore += score;
            }
        }
    }
    cout<<totScore;
}
#include<iostream>
#include<set>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    // Get the different frequencies of antennas used and their locations
    unordered_map<char, vector<pair<int, int>>> locations;  
    int rows= 50, cols = 50;
    for(int i = 0; i<rows; i++)
    {
        string input;
        cin>>input;
        for(int j = 0; j < cols; j++)
        {
            if(input[j]!='.')
            {
                locations[input[j]].push_back({i, j});
            }
        }
    }
    // Construct antinode of every pair in those locations
    // Say we have two locations {a1, b1} and {a2, b2}
    // Antinode location 1 = {a1, b1} - {a2-a1, b2-b1} = {2a1-a2, 2b1-b2}
    // Antinode location 2 = {a2, b2} - {a1-a2, b1-b2} = {2a2-a1, 2b2-b1}
    // For each frequency create a set and add the locations (we need unique locations for a given frequency)
    // Also they should be within in the matrix
    set<pair<int, int>> uniquelocations;
    for(auto frequencyLocation: locations)
    {
        
        vector<pair<int,int>> towerLocations = frequencyLocation.second;
        for(int i = 0; i<towerLocations.size()-1; i++)
        {
            for(int j = i+1; j<towerLocations.size(); j++)
            {
                pair<int, int> anLoc1 = {2*towerLocations[i].first-towerLocations[j].first, 2*towerLocations[i].second-towerLocations[j].second};
                pair<int, int> anLoc2 = {2*towerLocations[j].first-towerLocations[i].first, 2*towerLocations[j].second-towerLocations[i].second};
                if(anLoc1.first < rows && anLoc1.second < cols && anLoc1.first >= 0 && anLoc1.second >= 0) uniquelocations.insert(anLoc1);
                if(anLoc2.first < rows && anLoc2.second < cols && anLoc2.first >= 0 && anLoc2.second >= 0) uniquelocations.insert(anLoc2);
            }
        }
    }
    cout<<uniquelocations.size();
}
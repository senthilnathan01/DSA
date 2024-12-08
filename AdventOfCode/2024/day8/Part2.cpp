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

    set<pair<int, int>> uniquelocations;
    for(auto frequencyLocation: locations)
    {
        vector<pair<int,int>> towerLocations = frequencyLocation.second;
        for(int i = 0; i<towerLocations.size()-1; i++)
        {
            for(int j = i+1; j<towerLocations.size(); j++)
            {
                int diff1 = towerLocations[i].first-towerLocations[j].first;
                int diff2 = towerLocations[i].second-towerLocations[j].second;
                int multiples = 1.5*rows/min(abs(diff1), abs(diff2)); //rough estimate of the multiples
                for(int mul = 0; mul<=multiples; mul++)
                {
                pair<int, int> anLoc1 = {towerLocations[i].first + mul*diff1, towerLocations[i].second + mul*diff2};
                pair<int, int> anLoc2 = {towerLocations[j].first - mul*diff1, towerLocations[j].second - mul*diff2};
                if(anLoc1.first < rows && anLoc1.second < cols && anLoc1.first >= 0 && anLoc1.second >= 0) uniquelocations.insert(anLoc1);
                if(anLoc2.first < rows && anLoc2.second < cols && anLoc2.first >= 0 && anLoc2.second >= 0) uniquelocations.insert(anLoc2);
                }
            }
        }
    }
    cout<<uniquelocations.size();
}
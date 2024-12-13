#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<algorithm>

using namespace std;

int lowerbound(set<int>& nums, int x)
{
    auto it = nums.lower_bound(x);
    if (it == nums.begin()) {
        // If no element is less than x, return -1
        return -1;
    }
    // Move iterator back to the previous element
    --it;
    return *it;
}

int upperbound(set<int>& nums, int x)
{
    // Find the first element greater than x
    auto it = nums.upper_bound(x);
    if (it == nums.end()) {
        // If no such element exists, return -1
        return -1;
    }
    // Return the found element
    return *it;
}

int main()
{
    int m = 130, n = 130;
    vector<vector<int>> positions;
    unordered_map<int, int> hashincolumns;
    unordered_map<int, int> hashinrows;
    unordered_map<int, set<int>> hashcoltorows; // Stores row no and the locations of the hashes in it(col nos) 
    unordered_map<int, set<int>> hashrowtocols; // Stores col no and the locations of the hashes in it(row nos)
    set<pair<int,int>> distinctplaces;
    pair<int, int> guardpos;
    for(int i = 0; i< 130; i++)
    {
        string input;
        cin>>input;
        for(int j = 0; j < 130; j++) 
        {
            if(input[j]=='#'){
                positions.push_back({i, j});
                hashincolumns[j]=1;
                hashinrows[i]=1;
            }
            if(input[j]=='^') guardpos = {i, j};
        }
    }
    cout<<guardpos.first<<" "<<guardpos.second<<endl;
    // for(auto num:positions)
    // {
    //     cout<<num[0]<<" "<<num[1]<<endl;
    // }
    // cout<<endl;
    for(auto num: positions)
    {
        hashcoltorows[num[1]].insert(num[0]);
        hashrowtocols[num[0]].insert(num[1]);
    }

    // for(auto pair: hashcoltorows)
    // {
    //     cout<<pair.first<<"-";
    //     for(auto num: pair.second) cout<<num<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(auto pair: hashrowtocols)
    // {
    //     cout<<pair.first<<"-";
    //     for(auto num: pair.second) cout<<num<<" ";
    //     cout<<endl;
    // }

    int flag = 1; // The guard is still in the space
    // 1 - up, 2 - right, 3 - down, 4 - left
    int direction = 1;
    while(flag)
    {
        if(direction ==1)
        {
            int obstaclepos = lowerbound(hashcoltorows[guardpos.second], guardpos.first);
            if(obstaclepos==-1)
            {
                flag = 0;
                for(int i=guardpos.first; i>=0; i--)
                {
                    distinctplaces.insert({i, guardpos.second});
                }
                break;
            }
            else
            {
                for(int i=guardpos.first; i>=obstaclepos+1; i--)
                {
                    distinctplaces.insert({i, guardpos.second});
                }
                guardpos.first = obstaclepos + 1;
                direction = 2;
            }
            cout<<guardpos.first<<" "<<guardpos.second<<endl;
        }
        else if(direction ==2)
        {
            int obstaclepos = upperbound(hashrowtocols[guardpos.first], guardpos.second);
            if(obstaclepos==-1)
            {
                flag = 0;
                for(int i=guardpos.second; i<=n-1; i++)
                {
                    distinctplaces.insert({guardpos.first, i});
                }
                break;
            }
            else 
            {
                for(int i=guardpos.second; i<=obstaclepos-1; i++)
                {
                    distinctplaces.insert({guardpos.first, i});
                }
                guardpos.second = obstaclepos - 1;
                direction = 3;
            }
            cout<<guardpos.first<<" "<<guardpos.second<<endl;
        }
        else if(direction ==3)
        {
            int obstaclepos = upperbound(hashcoltorows[guardpos.second], guardpos.first);
            if(obstaclepos==-1)
            {
                flag = 0;
                for(int i=guardpos.first; i<=m-1; i++)
                {
                    distinctplaces.insert({i, guardpos.second});
                }
                break;
            }
            else
            {
                for(int i=guardpos.first; i<=obstaclepos-1; i++)
                {
                    distinctplaces.insert({i, guardpos.second});
                }
                guardpos.first = obstaclepos - 1;
                direction = 4;
            } 
            cout<<guardpos.first<<" "<<guardpos.second<<endl;
        }
        else
        {
            int obstaclepos = lowerbound(hashrowtocols[guardpos.first], guardpos.second);
            if(obstaclepos==-1)
            {
                flag = 0;
                for(int i=guardpos.second; i>=0; i--)
                {
                    distinctplaces.insert({guardpos.first, i});
                }
                break;
            }
            else 
            {
                for(int i=guardpos.second; i>=obstaclepos+1; i--)
                {
                    distinctplaces.insert({guardpos.first, i});
                }
                guardpos.second = obstaclepos + 1;
                direction = 1;
            }
            cout<<guardpos.first<<" "<<guardpos.second<<endl;
        }
    }

    cout<<distinctplaces.size();
}

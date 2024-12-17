#include<iostream>
#include<vector>
#include<string>
#define ll long long int
using namespace std;

int main()
{
    int rows = 50, cols = 50;
    vector<string> map(rows); //Stores the map
    for(int i = 0; i<rows; i++) getline(cin, map[i]);
    string temp;
    string robotMoves; //Has all the robot moves stored in a single string
    for(int i = 0; i<20; i++)
    {
        getline(cin, temp);
        robotMoves.append(temp);
    } 

    // Find @ in the map to get the robot's initial position
    pair<int, int> robotPos;
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            if(map[i][j]=='@') 
            {
                robotPos = {i,j};
                break;
            }
        }
    }

    int n = robotMoves.size();
    for(int currentRoboMove = 0; currentRoboMove<n; currentRoboMove++)
    {
        char dir = robotMoves[currentRoboMove];
        int i = robotPos.first;
        int j = robotPos.second;
        if(dir == '<')
        {
            while(j>0 && map[i][j]!='.')
            {
                if(map[i][j]=='#') break;
                j--;
            }
            if(map[i][j]=='.')
            {
                while(j!=robotPos.second)
                {
                    swap(map[i][j], map[i][j+1]);
                    j++;
                }
                robotPos = {i, j-1};
            }
        }
        else if(dir == '^')
        {
            while(i>0 && map[i][j]!='.')
            {
                if(map[i][j]=='#') break;
                i--;
            }
            if(map[i][j]=='.')
            {
                while(i!=robotPos.first)
                {
                    swap(map[i][j], map[i+1][j]);
                    i++;
                }
                robotPos = {i-1, j};
            }
        }
        else if(dir == '>')
        {
            while(j<cols-1 && map[i][j]!='.')
            {
                if(map[i][j]=='#') break;
                j++;
            }
            if(map[i][j]=='.')
            {
                while(j!=robotPos.second)
                {
                    swap(map[i][j], map[i][j-1]);
                    j--;
                }
                robotPos = {i, j+1};
            }
        }
        else 
        {
            while(i<rows-1 && map[i][j]!='.')
            {
                if(map[i][j]=='#') break;
                i++;
            }
            if(map[i][j]=='.')
            {
                while(i!=robotPos.first)
                {
                    swap(map[i][j], map[i-1][j]);
                    i--;
                }
                robotPos = {i+1, j};
            }
        }
    }
    ll sum = 0;
    for(int i = 1; i<rows-1; i++)
    {
        for(int j = 1; j<cols-1; j++)
        {
            if(map[i][j]=='O') sum+= (ll)(100*i+j);
        }
    }
    cout<<sum;
    
}
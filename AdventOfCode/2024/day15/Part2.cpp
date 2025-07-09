#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<set>

using namespace std;

map<char, pair<int, int>> inst = 
{
    {'^', {-1, 0}}, // Up
    {'>', {0, 1}}, // Right
    {'v', {1, 0}}, // Down
    {'<', {0, -1}} // Left
};

int mapsize = 50; // Change here 
int robotMoveLines = 20; // Change here

vector<string> mpp(mapsize);
vector<string> newmpp(mapsize);
string robotMoves;
pair<int, int> robotPos;

void constructNewMap()
{
    for(int currRow = 0; currRow < mapsize; currRow++)
    {
        string rowString = mpp[currRow];
        for(char character: rowString) 
        {
            if(character == '#') newmpp[currRow].append("##");
            else if(character == 'O') newmpp[currRow].append("[]");
            else if(character == '.') newmpp[currRow].append("..");
            else newmpp[currRow].append("@.");
        }
        // cout<<newmpp[currRow]<<endl;
    }
}

int main()
{
    // GETTING THE INPUT DATA:

    // Get the map
    for(int i = 0; i < mapsize; i++) cin>>mpp[i];

    //Let's get the robot's moves too
    string temp;
    for(int i = 0; i < robotMoveLines; i++) 
    {
        cin>>temp;
        robotMoves.append(temp);
    }

    // Construct the new map
    constructNewMap();

    // Find the robot's initial Pos == Find the location of @
    for(int currRow = 0; currRow < mapsize; currRow++)
    {
        for(int currCol = 0; currCol < mapsize; currCol++)
        {
            if(mpp[currRow][currCol] == '@')
            {
                robotPos = {currRow, 2*currCol};
                break;
            }
        }
    }

    // The process starts
    for(char robotMove : robotMoves)
    {
        pair<int, int> change = inst[robotMove];
        pair<int, int> newRobotPos = {robotPos.first + change.first, robotPos.second + change.second};

        switch(newmpp[newRobotPos.first][newRobotPos.second])
        {
            case ('#'):
                continue;
                break;

            case ('.'):
                newmpp[robotPos.first][robotPos.second] = '.';
                robotPos = newRobotPos;
                newmpp[robotPos.first][robotPos.second] = '@';
                break;

            case ('['):
            case (']'):
                queue<pair<int, int>> Q;
                Q.push(robotPos);
                set<pair<int, int>> seen;
                bool moveable = true;
                while(!Q.empty())
                {
                    pair<int, int> nc = Q.front();
                    Q.pop();
                    if(seen.count(nc)) continue;
                    seen.insert(nc);
                    pair<int, int> ncc = {nc.first + change.first, nc.second + change.second};
                    switch (newmpp[ncc.first][ncc.second])
                    {
                        case ('#'):
                            moveable = false;
                            break;
                        case ('['):
                            Q.push(ncc);
                            Q.push({ncc.first, ncc.second + 1});
                            break;
                        case (']'):
                            Q.push(ncc);
                            Q.push({ncc.first, ncc.second - 1});
                            break;
                    }
                }   

                if(moveable)
                {
                    while(!seen.empty())
                    {
                        for(auto it = seen.begin(); it != seen.end();)
                        {
                            pair<int, int> nc = *it;
                            pair<int, int> ncc = {nc.first + change.first, nc.second + change.second};
                            if(seen.count(ncc)==0)
                            {
                                newmpp[ncc.first][ncc.second] = newmpp[nc.first][nc.second];
                                newmpp[nc.first][nc.second] = '.';
                                it = seen.erase(it);
                            }
                            else ++it;
                        }
                    }
                    robotPos = newRobotPos;
                }
                break;
        }
    }

    // Get the scores
    int sum = 0;
    for(int currRow = 0; currRow < mapsize; currRow++)
    {
        for(int currCol = 0; currCol < 2*mapsize; currCol++)
        {
            if(newmpp[currRow][currCol] == '[') sum += 100*currRow + currCol;
        }
    }


    cout<<sum;

    return 0;
}
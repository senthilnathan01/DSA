#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;

/*
What are we given:
Initial map that has boxes, blocks and a robot.
The robots' moves.

What we want? The final map -> sum of all boxes' GPS coordinates. 

Process:
- Iterative one:
- We see the current map. 
- Get the robot's next move
- Make change in the map.
- That's it.

More Detail please:
- get the map data. store it in map<string>
- get the robot's moves. store it in string robotMoves 
- iteration is (for char in robot_moves<string>)
- we know the current robotpos
- we know it's next move
- we see few scenarios 

- scenario 1:
- will move == there is an empty space

- scenario 2:
- will not move == there is no empty space

*/

int mapsize = 50; //// Change here
int robotMoveLines = 20; //// Change here

vector<string> mpp(mapsize);
string robotMoves;
pair<int, int> robotPos;
pair<int, int> nextPlace;

pair<int, int> getNextPlace(char robotMove)
{
    switch (robotMove)
    {
        case '<':
            return {robotPos.first, robotPos.second -1};
            break;
        case '^':
            return {robotPos.first -1, robotPos.second};
            break;
        case '>':
            return {robotPos.first, robotPos.second + 1};
            break;
        case 'v':
            return {robotPos.first + 1, robotPos.second};
            break;
    }
}

pair<int, int> checkSpace(char robotMove)
{
    // return the emptySpace and return -1 if no empty space
    pair<int, int> emptySpace = robotPos;
    switch (robotMove)
    {
        case '<':
            emptySpace.second -= 1;
            while(emptySpace.second > 0 && mpp[emptySpace.first][emptySpace.second]=='O')
            {
                emptySpace.second--;
            } 
            break;
        case '^':
            emptySpace.first -= 1;
            while(emptySpace.first > 0 && mpp[emptySpace.first][emptySpace.second]=='O')
            {
                emptySpace.first--;
            }
            break;             
        case '>':
            emptySpace.second += 1;
            while(emptySpace.second < mapsize && mpp[emptySpace.first][emptySpace.second]=='O')
            {
                emptySpace.second++;
            }        
            break;     
        case 'v':
            emptySpace.first += 1;
            while(emptySpace.first < mapsize && mpp[emptySpace.first][emptySpace.second]=='O')
            {
                emptySpace.first++;
            } 
            break;
    }    
    if(mpp[emptySpace.first][emptySpace.second]=='.') return emptySpace;
    else return {-1, -1};
}

void updateMap(char robotMove)
{
    pair<int, int> nextPlace = getNextPlace(robotMove);
    switch (mpp[nextPlace.first][nextPlace.second])
    {
        case ('.'):
            // Update the map
            mpp[nextPlace.first][nextPlace.second] = '@';
            mpp[robotPos.first][robotPos.second] = '.';
            // Update the robotPos
            robotPos = nextPlace;
            break;

        case ('O'):
            // Check if there is a space to move the box to
            pair<int, int> emptySpace = checkSpace(robotMove);
            if(emptySpace.first != -1 && emptySpace.second != -1)
            {
                mpp[nextPlace.first][nextPlace.second] = '@';
                mpp[robotPos.first][robotPos.second] = '.';
                mpp[emptySpace.first][emptySpace.second] = 'O';
                robotPos = nextPlace;
            }
            break;
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

    // Find the robot's initial Pos == Find the location of @
    for(int currRow = 0; currRow < mapsize; currRow++)
    {
        for(int currCol = 0; currCol < mapsize; currCol++)
        {
            if(mpp[currRow][currCol] == '@')
            {
                robotPos = {currRow, currCol};
                break;
            }
        }
    }

    // The process starts:
    int num_iters = robotMoves.size();
    for(char robotMove : robotMoves)
    {
        updateMap(robotMove);
    }

    // Get the sum, man
    int sum = 0;
    for(int currRow = 0; currRow < mapsize; currRow++)
    {
        for(int currCol = 0; currCol < mapsize; currCol++)
        {
            if(mpp[currRow][currCol] == 'O') sum += currRow*100 + currCol;
        }
    }
    
    cout<<sum;

    return 0;
}

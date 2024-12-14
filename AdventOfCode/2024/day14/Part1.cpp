#include<iostream>
#include<regex>
#include<string>
#include<map>

using namespace std;

int main()
{
    int wide = 101, tall = 103;
    int noRobots  = 500;
    int times = 100;
    map<pair<int, int>, int> loc;
    while(noRobots--)
    {   
        string input;
        getline(cin, input);
        regex pattern(R"(p=(\d+),(\d+)\s*v=([\d-]+),([\d-]+))");
            
        int x, y, vx, vy;
        smatch match;
        if (regex_match(input, match, pattern)) {
            // Convert the matched groups to integers
            x = stoi(match[1].str());
            y = stoi(match[2].str());
            vx = stoi(match[3].str());
            vy = stoi(match[4].str());
        }
        // Final position
        x = (x + vx*times)%(wide);
        if(x<0) x+= wide;
        y = (y+ vy*times)%(tall);
        if(y<0) y+= tall;
        loc[{x,y}]++;
    }

    int q1=0, q2=0, q3=0, q4=0;
    int hor = wide/2, ver = tall/2;
    for(auto p: loc)
    {
        int num = p.second;
        pair<int, int> location = p.first;
        int loc1 = location.first, loc2 = location.second;
        if(loc1<hor && loc2<ver) q1 += num;
        else if(loc1 < hor && loc2 > ver) q3 += num;
        else if(loc1>hor && loc2 < ver) q2 += num;
        else if(loc1>hor && loc2 > ver) q4 += num;
    }
    cout<<(q1*q2*q3*q4);
}
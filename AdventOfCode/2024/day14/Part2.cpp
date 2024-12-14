#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Robot {
    int px, py; // Position
    int vx, vy; // Velocity
};

struct PairHash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        return hash<T1>()(p.first) ^ (hash<T2>()(p.second) << 1);
    }
};

const vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

// Function to simulate robot positions after a given time
unordered_set<pair<int, int>, PairHash> simulate(const vector<Robot>& robots, int time, int tall, int wide) {
    unordered_set<pair<int, int>, PairHash> positionsSet;
    for (size_t i = 0; i < robots.size(); ++i) {
        int x = (robots[i].px + time * robots[i].vx)%wide;
        if(x<0) x+= wide;
        int y = (robots[i].py + time * robots[i].vy)%tall;
        if(y<0) y+= tall;
        positionsSet.insert(make_pair(x, y));
    }
    return positionsSet;
}

// Perform DFS to find the size of the connected component
int dfs(pair<int, int> start, unordered_set<pair<int, int>, PairHash>& positionsSetCopy) {
    stack<pair<int, int>> s;
    s.push(start);
    int size = 0;

    // Remove the starting point from the set
    positionsSetCopy.erase(start);

    while (!s.empty()) {
        auto posPair = s.top();
        int x = posPair.first;
        int y = posPair.second;
        s.pop();
        size++;

        for (auto dirPair : directions) {
            int dx = dirPair.first;
            int dy = dirPair.second;
            pair<int, int> neighbor = {x + dx, y + dy};
            if (positionsSetCopy.find(neighbor) != positionsSetCopy.end()) {
                // Remove the neighbor from the set and add to stack
                positionsSetCopy.erase(neighbor);
                s.push(neighbor);
            }
        }
    }
    return size;
}

int nearby_robots(const unordered_set<pair<int, int>, PairHash>& positionsSet)
{
    int num = 0;
    unordered_set<pair<int, int>, PairHash> positionsSetCopy = positionsSet;
    while (!positionsSetCopy.empty()) {
        // Start DFS from any remaining robot
        auto it = positionsSetCopy.begin();
        num = max(num, dfs(*it, positionsSetCopy));
    }

    return num;
}

// Function to visualize the robots' positions
void visualize(const unordered_set<pair<int, int>, PairHash>& positionsSet, int tall, int wide) {
    vector<vector<char>> grid(tall, vector<char>(wide, '.'));
    for (size_t i = 0; i < positionsSet.size(); ++i) {
        auto p = *next(positionsSet.begin(), i);
        int x = p.first;
        int y = p.second;
        grid[y][x] = '#';
    }

    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

int main() {
    // Input robots data
    vector<Robot> robots;
    string line;
    regex pattern(R"(p=(-?\d+),(-?\d+) v=(-?\d+),(-?\d+))");

    while (getline(cin, line)) {
        smatch match;
        if (regex_match(line, match, pattern)) {
            robots.push_back(Robot{stoi(match[1].str()), stoi(match[2].str()),
                                   stoi(match[3].str()), stoi(match[4].str())});
        }
    }

    int tall = 103, wide = 101;

    // Number of nearby robots
    int minNum = 100;
    int times = 10000;
    for(int t = 0; t<times; t++)
    {
        unordered_set<pair<int, int>, PairHash> positionsSet;
        positionsSet = simulate(robots, t, tall, wide);
        if(nearby_robots(positionsSet)>minNum)
        {   
            cout<<"Time: "<<t<<endl;
            visualize(positionsSet, tall, wide);
        }
    }
    return 0;
}

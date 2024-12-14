#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

// Directions for movement: up, right, down, left
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct Guard {
    int x, y, dir;
};

bool isValid(int x, int y, const vector<string>& map) {
    return x >= 0 && x < map.size() && y >= 0 && y < map[0].size();
}

// Simulate the guard's movement and check if they get stuck in a loop
bool isStuckInLoop(int startX, int startY, int startDir, vector<string> map) {
    set<tuple<int, int, int>> visited;
    Guard guard = {startX, startY, startDir};

    while (true) {
        // If this state is already visited, the guard is in a loop
        auto state = make_tuple(guard.x, guard.y, guard.dir);
        if (visited.count(state)) return true;
        visited.insert(state);

        int nx = guard.x + dx[guard.dir];
        int ny = guard.y + dy[guard.dir];

        // Check if the guard moves out of bounds
        if (!isValid(nx, ny, map)) return false;

        if (map[nx][ny] == '#') {
            // Obstacle ahead, turn right
            guard.dir = (guard.dir + 1) % 4;
        } else {
            // Move forward
            guard.x = nx;
            guard.y = ny;
        }
    }
}

int main() {
    vector<string> map;
    string line;

    // Read the input map
    while (getline(cin, line) && !line.empty()) {
        map.push_back(line);
    }

    // Find the guard's starting position and direction
    int startX, startY, startDir;
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if (map[i][j] == '^') startX = i, startY = j, startDir = 0;
        }
    }

    int loopPositions = 0;

    // Check every possible position on the map
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            // Skip the guard's starting position or existing obstacles
            if ((i == startX && j == startY) || map[i][j] == '#') continue;

            // Place a new obstruction
            map[i][j] = '#';

            // Check if the guard gets stuck in a loop
            if (isStuckInLoop(startX, startY, startDir, map)) {
                ++loopPositions;
            }

            // Remove the obstruction
            map[i][j] = '.';
        }
    }

    cout << loopPositions << endl;
    return 0;
}

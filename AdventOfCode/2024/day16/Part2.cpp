#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <set>
#include <map>
#include <stack>
using namespace std;

const int mapr = 141, mapc = 141;
vector<string> mpp(mapr);

pair<int, int> start = {mapr - 2, 1};
pair<int, int> end_ = {1, mapc - 2};

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int getDirIndex(int dx, int dy) {
    for (int i = 0; i < 4; ++i)
        if (dr[i] == dx && dc[i] == dy) return i;
    return -1;
}

int main() {
    for (int row = 0; row < mapr; row++) cin >> mpp[row];

    int sx = start.first, sy = start.second;
    int ex = end_.first, ey = end_.second;

    int sd = 1; // start facing east
    using State = tuple<int, int, int>; // row, col, dir
    using PState = pair<int, State>;

    priority_queue<PState, vector<PState>, greater<>> pq;
    map<State, int> dist;
    map<State, set<State>> from;

    State start_state = {sx, sy, sd};
    pq.push({0, start_state});
    dist[start_state] = 0;

    int bestCost = INT_MAX;
    vector<int> bestDirs;

    while (!pq.empty()) {
        auto [d, s] = pq.top(); pq.pop();
        int x, y, dir; tie(x, y, dir) = s;
        if (dist[s] < d) continue;

        if (x == ex && y == ey) {
            if (d < bestCost) {
                bestCost = d;
                bestDirs.clear();
            }
            if (d == bestCost) bestDirs.push_back(dir);
        }

        // Turn left and right
        for (int dd : {-1, 1}) {
            int ndir = (dir + dd + 4) % 4;
            State ns = {x, y, ndir};
            if (dist.find(ns) == dist.end() || dist[ns] > d + 1000) {
                dist[ns] = d + 1000;
                pq.push({d + 1000, ns});
                from[ns] = {s};
            } else if (dist[ns] == d + 1000) {
                from[ns].insert(s);
            }
        }

        // Forward
        int nx = x + dr[dir], ny = y + dc[dir];
        if (nx >= 0 && nx < mapr && ny >= 0 && ny < mapc && mpp[nx][ny] != '#') {
            State ns = {nx, ny, dir};
            if (dist.find(ns) == dist.end() || dist[ns] > d + 1) {
                dist[ns] = d + 1;
                pq.push({d + 1, ns});
                from[ns] = {s};
            } else if (dist[ns] == d + 1) {
                from[ns].insert(s);
            }
        }
    }

    cout << bestCost << endl;

    set<State> gnodes;
    for (int d : bestDirs) gnodes.insert({ex, ey, d});
    stack<State> stk;
    for (auto s : gnodes) stk.push(s);

    while (!stk.empty()) {
        State s = stk.top(); stk.pop();
        for (auto prev : from[s]) {
            if (gnodes.insert(prev).second) {
                stk.push(prev);
            }
        }
    }

    set<pair<int, int>> coords;
    for (auto [x, y, _] : gnodes) coords.insert({x, y});

    int count = 0;
    for (int i = 0; i < mapr; ++i) {
        for (int j = 0; j < mapc; ++j) {
            if (coords.count({i, j}) && mpp[i][j] != '#' && mpp[i][j] != 'S' && mpp[i][j] != 'E') {
                mpp[i][j] = 'O';
                count++;
            }
        }
    }

    cout << "Tiles on best paths = " << count << endl;
    for (auto &row : mpp) cout << row << endl;
    return 0;
}

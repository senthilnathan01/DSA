#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<set>

using namespace std;

int mapr = 141, mapc=141;
vector<string> mpp(mapr);

// Just use priority queue
// Add rotation as one of the moves - have the corresponding cost too
// Maintain a set of already seen location_rotation (r, c, dir_r, dir_c)

// Directions:
// Up = {-1, 0}
// Right = {0, 1}
// Down = {1, 0}
// Left = {0, -1}

// The pattern is that if ur current orientation is {dirRow, dirCol},
// the neighbouring orientations (that come after 90 deg rotation) are:
// {-dirCol, dirRow}
// {dirCol, -dirRow}

// You can get the same using the transformation matrix of
// [c -s]
// [s c]
// with theta being 90, u get 
// [0 -1]
// [1 0]
// multipling with [x y] we get
// [-y x]

// if theta is -90 
// [0 1]
// [-1 0]
// we get [y -x] after that

// Also I already know the location of S and E, so hardcoding it here
pair<int, int> start = {mapr - 2, 1};
pair<int, int> end = {1, mapc -2};

int main()
{
    // Get the input kiddo
    for(int row = 0; row < mapr; row++) cin>>mpp[row];

    using State = tuple<int, int, int, int, int>;
    // Initialise the PQ
    auto cmp = [](const State& a, const State& b) { return get<0>(a) > get<0>(b); };
    priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);

    int sr = start.first, sc = start.second;    
    pq.emplace(0, sr, sc, 0, 1);

    int min_cost = INT_MAX;
    vector<vector<int>> seen(mapr, vector<int>(mapc,-1));

    seen[sr][sc] = 0;

    while(!pq.empty())
    {
        auto [cost, row, col, dirRow, dirCol] = pq.top();
        pq.pop();

        if(cost > min_cost) continue;

        if(mpp[row][col] == 'E'){
            min_cost = min(min_cost, cost);
            continue;
        } 

        // possible moves
        vector<State> moves = 
        {
            {cost + 1, row +  dirRow, col + dirCol, dirRow, dirCol},
            {cost + 1000, row, col, dirCol, -dirRow},
            {cost + 1000, row, col, -dirCol, dirRow}
        };

        for(const auto& [newCost, newRow, newCol, newdirRow, newdirCol] : moves)
        {
            // Skip out of bounds or blocked cell
            if(newRow < 0 || newRow >= mapr || newCol < 0 || newCol >= mapc || mpp[newRow][newCol] == '#') continue;

            // skip if already seen, add to seen if not seen
            if(seen[newRow][newCol]== -1)
            {
                // Not seen yet
                seen[newRow][newCol] = newCost;
            }

            // ignore if we have a better cost
            if(seen[newRow][newCol] + 2000 < newCost) continue;
            // 2000 is just random, I just wanted something above 1000? 1001? 

            pq.emplace(newCost, newRow, newCol, newdirRow, newdirCol);
        }
    }

    cout<<min_cost;

    return 0;
}
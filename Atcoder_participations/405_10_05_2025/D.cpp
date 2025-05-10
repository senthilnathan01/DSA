#include<bits/stdc++.h>
using namespace std;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int h, w; 
vector<string> inputS;

bool isValid(int r, int c)
{
    return  0<=r && r<h && 0<=c && c < w && inputS[r][c] == '.';
}

char sym(int dir)
{
    switch(dir)
    {
        case 0: return 'v';
        case 1: return '^';
        case 2: return '>';
        case 3: return '<';
        default: return '?';
    }
}

vector<string> solve()
{
    inputS.resize(h);
    for(int i = 0; i < h; i++) cin>>inputS[i];
    vector<string> ans = inputS;

    vector<pair<int, int>> exits;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(inputS[i][j]=='E') exits.push_back({i, j});
        }
    }

    vector<vector<int>> d(h, vector<int>(w, INT_MAX));
    queue<pair<pair<int, int>, int>> locs;

    for(auto exit: exits)
    {
        locs.push({exit, 0});
        d[exit.first][exit.second] = 0;
    }

    while(!locs.empty())
    {
        auto current = locs.front();
        locs.pop();
        int r = current.first.first;
        int c = current.first.second;
        int distance = current.second;

        for(int dir = 0; dir < 4; dir++)
        {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if(isValid(nr, nc))
            {
                if(d[nr][nc]>distance + 1)
                {
                    d[nr][nc]=distance + 1;
                    ans[nr][nc] = sym(dir);
                    locs.push({{nr, nc}, distance + 1});
                }
            }
        }
    }
    return ans;
}

int main()
{
    cin>>h>>w;
    vector<string> ans = solve();
    for(auto s: ans) cout<<s<<endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

map<int, set<int>> set1;
map<int, set<int>> set2;

int h, w, n;

int main()
{
    cin>>h>>w>>n;
    int x, y;
    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;
        set1[x].insert(y);
        set2[y].insert(x);
    }

    int q; cin>>q;
    int condition = 1;
    while(q--)
    {
        cin>>condition;
        if(condition == 1)
        {
            cin>>x;
            cout<<set1[x].size()<<endl;
            for(auto num: set1[x])
            {
                set2[num].erase(x);
            }
            set1[x].clear();
        }
        else
        {
            cin>>y;
            cout<<set2[y].size()<<endl;
            for(auto num: set2[y])
            {
                set1[num].erase(y);
            }
            set2[y].clear();
        }
    }

    return 0;
}


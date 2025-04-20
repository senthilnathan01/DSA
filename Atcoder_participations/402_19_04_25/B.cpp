#include<bits/stdc++.h>

using namespace std;

int main()
{
    int q; cin>>q;
    queue<int> menu;
    int num;
    while(q--)
    {
        int query; cin>>query;
        if(query==1)
        {
            cin>>num;
            menu.push(num);
        }
        else
        {
            cout<<menu.front()<<endl;
            menu.pop();
        }
    }
}

#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin>>n>>m>>q;

    set<int> users_with_all_permissions;
    map<int, set<int>> individual_permissions;

    int type, person, page;
    while(q--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>person>>page;
            if(users_with_all_permissions.find(person) == users_with_all_permissions.end())
            {
                individual_permissions[person].insert(page);
            }
        }
        else if(type == 2)
        {
            cin>>person;
            users_with_all_permissions.insert(person);
            if(individual_permissions.count(person)) {
                individual_permissions.erase(person);
            }
        }
        else
        {
            cin>>person>>page;
            if(users_with_all_permissions.count(person))
            {
                cout<<"Yes\n";
            }
            else
            {
                if(individual_permissions.count(person) && individual_permissions[person].count(page))
                {
                    cout<<"Yes\n";
                }
                else
                {
                    cout<<"No\n";
                }
            }
        }
    }

    return 0;
}

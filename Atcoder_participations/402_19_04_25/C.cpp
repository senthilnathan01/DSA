#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; cin>>n>>m;
    vector<vector<int>> dishes(m);
    vector<set<int>> dishToingre(m);
    for(int i = 0; i < m; i++)
    {
        int num_ingre; cin>>num_ingre;
        dishes[i].resize(num_ingre);
        for(int j = 0; j < num_ingre; j++)
        {
            cin>>dishes[i][j];
            dishToingre[i].insert(dishes[i][j]);
        }
    }

    // Ingredients -> dishes
    vector<vector<int>> ingreToDish(n+1);
    for(int i = 0; i < m; i++)
    {
        for(auto it: dishes[i])
        {
            ingreToDish[it].push_back(i);
        }
    }

    set<int> edibleDishes;
    int ingredient =0;
    for(int i = 1; i <= n; ++i)
    {
        cin>>ingredient;
        for(auto dish: ingreToDish[ingredient])
        {
            dishToingre[dish].erase(ingredient);
            if(dishToingre[dish].size()==0) edibleDishes.insert(dish);
        }
        cout<<edibleDishes.size()<<endl;
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> inputArr (m, 0);
    set<int> mySet;
    for(int i = 1; i <= n; i++)
    {   
        mySet.insert(i);
    }

    for(int i = 0; i < m ; i++) cin>>inputArr[i];
    for(int num: inputArr) mySet.erase(num);

    int c = mySet.size();
    cout<<c<<endl;
    for(int num: mySet) cout<<num<<" ";
    return 0;
}
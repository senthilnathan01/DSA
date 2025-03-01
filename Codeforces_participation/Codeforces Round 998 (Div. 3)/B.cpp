#include<iostream>
#include<vector>
#include<map>
#include<set>

#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve()
{
    int n, m;
    cin>>n>>m;

    map<int, set<int>> mpp;
    for(int i = 0; i<n; i++)
    {
        set<int> myset;
        for(int j = 0; j < m; j++)
        {
            int num;
            cin>>num;
            myset.insert(num);
        }
        mpp[i] = myset;
    }

    // Get the initial order
    set<int> cowSet;
    vector<int> arr(n, -1);
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(mpp[i].find(j)!=mpp[i].end())
            {
                if(cowSet.count(i)!=0)
                {
                    cout<<"-1"<<endl;
                    return;
                }
                arr[j] = i;
                cowSet.insert(i);
                break;
            }
        }
    }

    for(int time = 1; time < m; time++)
    {
        for(int j = time*n; j < time*n + n; j++)
        {
            int cow = arr[j - time*n];
            if(mpp[cow].find(j)==mpp[cow].end())
            {
                cout<<"-1"<<endl;
                return;
            }
        }
    }

    for(int num: arr) cout<<num+1<<" ";
    cout<<endl;
    return;
}

int main()
{
    CODE
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        solve();
    }
}

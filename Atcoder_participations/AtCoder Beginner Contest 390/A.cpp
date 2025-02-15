#include<iostream>
#include<vector>

using namespace std;

bool solve()
{
    vector<int> arr(5);
    for(int i = 0; i<5; i++)
    {
        cin>>arr[i];
    }

    int count = 0;

    for(int i = 0; i<=4; i++)
    {
        if(arr[i]!=i+1)
        {
            i++;
            if(arr[i]!=i+1)
            {
                count++;
            }
            else
            {
                return false;
            }
        }
    }
    if(count == 1) return true;
    return false;
}

int main()
{
    if(solve()) cout<<"Yes";
    else cout<<"No";
}
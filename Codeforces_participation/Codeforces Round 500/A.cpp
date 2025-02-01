#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, target;
    cin>>n>>target;
    vector<int> arr(n);

    arr[0] = 0;
    for(int i = 1; i<n; i++) cin>>arr[i];

    int pos = 1;
    bool reached = false;
    while(pos<target)
    {
        pos += arr[pos];
        if(pos==target)
        {
            reached = true;
            break;
        }
    }
    if(reached)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}

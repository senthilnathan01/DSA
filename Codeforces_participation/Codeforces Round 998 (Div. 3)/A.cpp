#include<iostream>
#include<vector>

#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve()
{
    vector<int> arr(4);
    for(int i = 0; i<5; i++)
    {
        if(i==2) arr[i] = 0;
        else
        {
            cin>>arr[i];
        }
    } 

    int max_count = 0;
    for(int i = 0; i<3; i++)
    {
        int a = INT32_MIN;
        if(i==0)
        {
            arr[2] = arr[i]+arr[i+1];
            int count = 0;
            for(int j = 0; j<3; j++)
            {
                if(arr[j]+arr[j+1] == arr[j+2]) count++;
            }
            max_count = max(max_count, count);
        }
        else if(i==1)
        {
            arr[2] = arr[i+1]-arr[i-1];
            int count = 0;
            for(int j = 0; j<3; j++)
            {
                if(arr[j]+arr[j+1] == arr[j+2]) count++;
            }
            max_count = max(max_count, count);    
        }
        else 
        {
            arr[2] = arr[i+2]-arr[i+1];
            int count = 0;
            for(int j = 0; j<3; j++)
            {
                if(arr[j]+arr[j+1] == arr[j+2]) count++;
            }
            max_count = max(max_count, count);  
        }
    }
    cout<<max_count<<endl; 
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

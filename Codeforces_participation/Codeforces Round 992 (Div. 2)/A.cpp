#include<iostream> 
#include<vector>

using namespace std;

int main()
{
    int testCases;
    cin>>testCases;

    while(testCases--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> numbers(n);
        for(int i = 0; i<n; i++)
        {
            cin>>numbers[i];
        }
        int ans;
        int flag = 1;
        for(int i = 0; i<n; i++)
        {
            flag = 1;
            for(int j = 0; j<n; j++)
            {
                if(j!=i && abs(numbers[i]-numbers[j])%k==0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 1)
            {
                cout<<"YES"<<endl;
                cout<<i+1<<endl;
                break;
            }
        }
        if(flag == 0) cout<<"NO"<<endl;
    }
}
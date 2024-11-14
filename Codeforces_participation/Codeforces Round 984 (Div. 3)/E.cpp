#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n,k,q;
    cin>>n>>k>>q;
    
    vector<vector<int>> Data(k+1, vector<int>(n+1));
    // Original Water Levels are stored in a matrix
    for(int i=1; i<=n; i++)
    {
        for(int j = 1; j<=k; j++) cin>> Data[j][i];
    }

    // Matrix contents after the sage redirects the rivers
    for(int i=2; i<=n; i++)
    {
        for(int j = 1; j<=k; j++) Data[j][i]|=Data[j][i-1];
    }

    // Let's carry out the queries
    while(q--)
    {
        // Get the number requirements
        int m;
        cin>>m;
        
        int low = 1, high = n+1;

        // Store the requirements
        for(int i = 0; i<m; i++)
        {
            int region, value;
            char condition;
            cin>>region>>condition>>value;
            
            if(condition == '<') high = min(high, int(lower_bound(Data[region].begin(), Data[region].end(), value)-Data[region].begin()));
            else low = max(low, int(upper_bound(Data[region].begin(), Data[region].end(), value)-Data[region].begin()));
        }
        cout<<(low>=high?-1:low)<<"\n";
    }  
}

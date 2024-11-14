#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void processTestCase(int n, int m)
{
    vector<string> vectorOfStrings(n);
    for(int i = 0; i<n; i++) cin>>vectorOfStrings[i];

    int number_of_layers = min(n/2, m/2);
    vector<string> layers;

    for(int i = 0; i<number_of_layers; i++)
    {
        int j = m-i-1;
        string layer="";
        layer += vectorOfStrings[i].substr(i, m-2*i);

        for(int row = i+1; row <= n-i-2; row++) layer += vectorOfStrings[row][j];
        
        string lastline = vectorOfStrings[n-i-1].substr(i, m-2*i);
        reverse(lastline.begin(), lastline.end());
        layer += lastline;

        j = i;
        for(int row = n-i-2; row >= i+1; row--) layer += vectorOfStrings[row][j];
        layer += layer.substr(0, 3);
        layers.push_back(layer);
    }

    int total_sum = 0;
    for(auto layer: layers)
    {
        int length = layer.size();
        for(int i = 0; i<=length-4; i++)
        {
            if(layer.substr(i, 4)=="1543") total_sum++;
        }
    }
    
    cout<<total_sum<<endl;
}


void solve()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, m;
        cin>>n>>m;
        processTestCase(n, m);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}

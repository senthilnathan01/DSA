#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int lines =140;
    int n = lines;
    vector<string> m;
    while(lines--)
    {
        string inputline;
        cin>>inputline;
        m.push_back(inputline);
    }

    int count = 0;
    for(int i = 1; i<=138; i++)
    {
        for(int j = 1; j<=138; j++)
        {
            if(m[i][j] == 'A')
            {
                // Do all the tests
                // Positions wrt M M

                // M M on the top
                if(m[i-1][j-1]=='M' && m[i-1][j+1]=='M' && m[i+1][j-1]=='S' && m[i+1][j+1]=='S') count++;
                // M M on the right
                if(m[i-1][j-1]=='S' && m[i-1][j+1]=='M' && m[i+1][j-1]=='S' && m[i+1][j+1]=='M') count++;
                // M M on the bottom
                if(m[i-1][j-1]=='S' && m[i-1][j+1]=='S' && m[i+1][j-1]=='M' && m[i+1][j+1]=='M') count++;
                // M M on the right
                if(m[i-1][j-1]=='M' && m[i-1][j+1]=='S' && m[i+1][j-1]=='M' && m[i+1][j+1]=='S') count++;
            }
        }
    }
    cout<<count;
}
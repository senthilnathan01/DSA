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
    for(int i = 0; i<140; i++)
    {
        for(int j = 0; j<140; j++)
        {
            if(m[i][j] == 'X')
            {
                // Do all the tests
                // Horizontal Check - 2 sides
                // Vertical check - 2 sides
                // Diagonal check - 4 sides

                // Horizontal Check
                // Right Side
                if(j<n-3 && m[i][j+1]=='M' && m[i][j+2]=='A' && m[i][j+3]=='S') count++;
                // Left Side
                if(j>=3 && m[i][j-1] == 'M' && m[i][j-2]=='A' && m[i][j-3]=='S') count++;

                // Vertical Check
                // Down Side
                if(i<n-3 && m[i+1][j]=='M' && m[i+2][j]=='A' && m[i+3][j]=='S') count++;
                // Upside Side
                if(i>=3 && m[i-1][j] == 'M' && m[i-2][j]=='A' && m[i-3][j]=='S') count++;

                // Diagonal Check
                // Towards up right
                if(i>=3 && j<n-3) if(m[i-1][j+1]=='M' && m[i-2][j+2]=='A' && m[i-3][j+3]=='S') count++;
                // Towards up left
                if(i>=3 && j>=3) if(m[i-1][j-1]=='M' && m[i-2][j-2]=='A' && m[i-3][j-3]=='S') count++;
                // Towards down right
                if(i<n-3 && j<n-3) if(m[i+1][j+1]=='M' && m[i+2][j+2]=='A' && m[i+3][j+3]=='S') count++;
                // Towards down left
                if(i<n-3 && j>=3) if(m[i+1][j-1]=='M' && m[i+2][j-2]=='A' && m[i+3][j-3]=='S') count++;
            }
        }
    }
    cout<<count;
}
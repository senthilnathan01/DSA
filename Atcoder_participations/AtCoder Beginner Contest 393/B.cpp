#include<bits/stdc++.h>

using namespace std;

int main()
{
    string inputString;
    cin>>inputString;

    vector<int> locA;
    vector<int> locB;
    vector<int> locC;

    int size = inputString.length();
    for(int i = 0; i < size; i++)
    {
        if(inputString[i]=='A') locA.push_back(i);
        else if(inputString[i]=='B') locB.push_back(i);
        else if(inputString[i]=='C') locC.push_back(i);
    }

    int nA = locA.size(), nB = locB.size(), nC = locC.size();
    if(nA == 0 || nB == 0 || nC == 0)
    {
        cout<<0;
        return 0;
    }
    int count = 0;
    for(int a = 0; a < nA; a++)
    {
        for(int b = 0; b < nB; b++)
        {
            if(locB[b]<locA[a])
            {
                continue;
            }
            else
            {
                for(int c = 0; c < nC; c++)
                {
                    if(locC[c]<locB[b])
                    {
                        continue;
                    }
                    else
                    {
                        if(locB[b]-locA[a] == locC[c] - locB[b])
                        {
                            count++;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout<<count;
    return 0;
}
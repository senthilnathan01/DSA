#include<iostream>
#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

int searchForDuplicate(string &inputstring)
{
    // return the index of duplicates
    int size = inputstring.length();
    for(int i = 0; i < size-1; i++) 
    {
        if(inputstring[i]==inputstring[i+1]) return i;
    }
    return -1;
}

void removalProcess(string &inputstring, int currentIndex)
{
    //remove
    inputstring.erase(currentIndex, 1);
    int size = inputstring.length();
    if(currentIndex+1 <= size-1)
    {
        inputstring[currentIndex] = inputstring[currentIndex+1];
    }
    else if(currentIndex-1>=0)
    {
        inputstring[currentIndex] = inputstring[currentIndex-1];
    }
    int startIndex = searchForDuplicate(inputstring);
    if(startIndex!=-1)
    {
        removalProcess(inputstring, startIndex);
    }
}

void solve()
{
    string inputstring;
    cin>>inputstring;
    int startIndex = searchForDuplicate(inputstring);
    if(startIndex!=-1)
    {
        removalProcess(inputstring, startIndex);
    }
    cout<<inputstring.length()<<endl;
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

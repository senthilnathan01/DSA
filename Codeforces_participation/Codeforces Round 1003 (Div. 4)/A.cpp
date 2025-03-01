#include<iostream>
#include<string>
#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve()
{
    string inputstring;
    cin>>inputstring;
    int size = inputstring.length();
    string newstring = inputstring.substr(0, size-2);
    cout<<newstring+"i"<<endl;
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

#include<iostream>
#include<set>
#define CODE ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

void solve()
{
    string s;
    cin>>s;
    
    int n = s.size();
    int queries;
    cin>>queries;
    
    if(n<4)
    {
        while(queries--)
        {
            int index; char c;
            cin>>index>>c;
            cout<<"NO"<<endl;
        }        
    }
    else
    {
        set<int> st;
        for(int i=0; i<=n-4; i++)
        {
            if(s.substr(i, 4)=="1100") st.insert(i);
        }
        while(queries--)
        {
            int index; char c;
            cin>>index>>c;
            index--;
            if(s[index]!=c)
            {
                s[index]=c;
                for(int j = index-3; j<=index ; j++)
                {
                    if(j<0) continue;
                    if(s.substr(j, 4)=="1100") st.insert(j);
                    else st.erase(j);
                }
            }
            cout<<(st.size()>0 ? "YES":"NO")<<endl;
        }
    }
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
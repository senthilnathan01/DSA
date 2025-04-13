#include<bits/stdc++.h>

using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

int main()
{
    fast
    int t; cin>>t;
    t++;
    while(t--)
    {
        string s; 
        getline(cin, s);
        string word;
        vector<string> v;
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' ')
            {
                word+=s[i];
            }
            else
            {
                v.push_back(word);
                if(i<s.length()+1) word.clear();
            }  
        }
        v.push_back(word);
        bool done = false;
        for(auto i:v){
            if(isalpha(i[0]))
            {
                done = true;
                cout<<i[0];
            }
        }
        if(done) cout<<endl;
    }
    return 0;
}

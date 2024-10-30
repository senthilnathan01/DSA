#include <iostream>
#include<climits>

using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int reversals = 0;
        char c = s[0];
        int length = INT_MAX;
        int reversal = 0;
        for(int i = 0; i<n; i++)
        {
            if(s[i]!=c) 
            {
                reversals++;
                c = s[i];
            }
        }

        if(reversals%2==0) cout<<n<<endl;
        else
        {
            int first_reversal;
            c = s[0];
            for(int i = 0; i<n; i++)
            {
                if(s[i]!=c){
                    first_reversal = i;
                    break;
                }
            }
            int last_reversal;
            c = s[n-1];
            for(int i = n-1; i>=0; i--)
            {
                if(s[i]!=c){
                    last_reversal = i;
                    break;
                }
            }
            int length = min(first_reversal, n-last_reversal-1);
            cout<<n-length<<endl;
        }
    }
}

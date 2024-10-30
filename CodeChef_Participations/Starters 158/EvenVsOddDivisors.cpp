#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N;
        cin>>N;
        vector<int> divisors;
        for(int i = 1; i<=sqrt(N); i++)
        {
            if(N%i==0){
                divisors.push_back(i);
                if(i!=N/i) divisors.push_back(N/i);
            }
        }
        int even=0, odd=0;
        for(int num: divisors)
        {
            if(num%2==0) even++;
            else odd++;
        }
        if(even>odd) cout<<1<<endl;
        else if(even == odd) cout<<0<<endl;
        else cout<<-1<<endl;   
	}
}

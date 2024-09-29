#include<iostream>
#include <cmath>
using namespace std;

int countDivisors(int n) 
{ 
	int cnt = 0; 
	for (int i = 1; i <= sqrt(n); i++) { 
		if (n % i == 0) { 
			if (n / i == i) cnt++; 
			else cnt = cnt + 2; 
		} 
	} 
	return cnt; 
} 

int main(){
    int test_cases;
    cin>>test_cases;

    for(int i=0; i<test_cases; i++){
        int k;
        cin>>k;
        int n=1;
        while(k>0){
          n+=1;
          if(countDivisors(n)%2==0){
            k=k-1;
          }
        }
        cout<<n<<endl;
    }
    return 0;
}
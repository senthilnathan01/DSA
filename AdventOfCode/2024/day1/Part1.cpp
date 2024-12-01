#include<iostream>
#define CODE ios::sync_with_stdio(false); cin.tie(0);
#include<vector>
#include<algorithm>

using namespace std;

void solve(int& sum)
{
    int testCases = 1000;
    vector<int> A(1000), B(1000);
    while(testCases--)
    {
        cin>>A[testCases]>>B[testCases];
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for(int i = 0; i< 1000; i++)
    {
        sum += abs(A[i]-B[i]);
    }
}

int main()
{
    CODE
    int sum = 0;
    solve(sum);
    cout<<sum;
}








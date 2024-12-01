#include<iostream>
#define CODE ios::sync_with_stdio(false); cin.tie(0);
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

void solve(int& sum)
{
    unordered_map<int, int> mpp;
    int testCases = 1000;
    vector<int> A(1000), B(1000);
    while(testCases--)
    {
        cin>>A[testCases]>>B[testCases];
    }
    for(int num: B) mpp[num]++;

    for(int num: A)
    {
        sum += num*mpp[num];
    }

}

int main()
{
    CODE
    int sum = 0;
    solve(sum);
    cout<<sum;
}








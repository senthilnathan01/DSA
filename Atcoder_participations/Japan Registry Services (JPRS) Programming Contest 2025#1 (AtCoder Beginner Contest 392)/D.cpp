#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include <iomanip>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin>>n;
    vector<map<int, int>> arr;
    vector<int> k (n, 0);
    for(int i = 0; i < n; i++)
    {
        map<int, int> mpp;
        cin >> k[i];
        for(int j = 0; j < k[i]; j++)
        {
            ll num;
            cin >> num;
            mpp[num]++;
        }
        arr.push_back(mpp);
    }

    long double maxProb = 0.0;
    for(int dice1 = 0; dice1 < n-1; dice1++)
    {
        long double prob = 0.0;
        for(int dice2 = dice1 + 1; dice2 < n; dice2++)
        {
            long double base = 1.0 * k[dice1] * k[dice2];
            for(auto mapEle: arr[dice1])
            {
                if(arr[dice2].find(mapEle.first)==arr[dice2].end()) continue;
                prob += 1.0 *(mapEle.second)*(arr[dice2][mapEle.first]);
            }
            prob /= base;
            maxProb = max(maxProb, prob);
        }
    }
    cout << fixed << setprecision(15) << maxProb ;
    return 0;
}
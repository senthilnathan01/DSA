#include<iostream>
#include<vector>
#include<cmath>
#define ll long long int
using namespace std;

int noOfdigits(ll a)
{
    int digits = 0;
    ll temp = a;
    while(temp>0)
    {
        temp /=10;
        digits++;
    }
    return digits;
}

pair<ll, ll> getTheHalves(ll num, int digits)
{
    int divideby = powf(10, digits/2);
    ll newNum = num%divideby;
    num/=divideby;
    return {num, newNum};
}

int main()
{
    int noBlinks = 25;
    int noOfNums = 8;
    vector<ll> stones;
    while(noOfNums--)
    {
        ll num;
        cin>>num;
        stones.push_back(num);
    }
    while(noBlinks--)
    {
        vector<ll> newConfig;
        for(int i = 0; i<stones.size(); i++)
        {
            int digits = noOfdigits(stones[i]);
            // Case1:
            if(stones[i]==0) newConfig.push_back(1);
            // Case2;
            else if(digits%2==0) //Even no of digits
            {
                pair<ll, ll> p = getTheHalves(stones[i], digits);
                newConfig.push_back(p.first);
                newConfig.push_back(p.second);
            }
            // Case 3:
            else
            {
                newConfig.push_back(stones[i]*2024);
            }
        }
        stones = newConfig;
        // for(ll num: stones) cout<<num<<" ";
        // cout<<endl;
    }
    cout<<stones.size();
}
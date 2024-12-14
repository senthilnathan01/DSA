#include<iostream>
#include<vector>

using namespace std;

void solve()
{
    int contests, rating;
    cin>>contests>>rating;
    int div1l = 1600, div1r = 2799, div2l = 1200, div2r = 2399;
    while(contests--)
    {
        int div, performance;
        cin>>div>>performance;
        if(div==1)
        {
            if(rating>=div1l && rating <= div1r)
            {
                rating += performance;
            }
        }
        else
        {
            if(rating >= div2l && rating <= div2r)
            {
                rating += performance;
            }
        }
    }
    cout<<rating;
}

int main()
{
    solve();
}
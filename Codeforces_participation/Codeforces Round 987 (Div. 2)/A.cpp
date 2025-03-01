#include<iostream>
#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve()
{
    int size;
    cin>>size;
    int mode = 1;
    int frequency = 1;
    int current_element = 0;
    cin>>current_element;
    int mode_element = current_element;
    int new_size = size -1;
    while(new_size--)
    {
        int element = 0;
        cin>>element;
        if(current_element==element) frequency++;
        else frequency = 1;
        current_element = element;
        if(frequency>mode)
        {
            mode = frequency;
            mode_element = element; 
        }
    }
    cout<< (size - mode)<<"\n";
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

#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

bool isSafe(string& input)
{
    istringstream iss(input);
    vector<int> num;

    int number;
    while (iss >> number) {
        num.push_back(number);
    }

    int flag =  1;
    int n = num.size();
    // Check if they are ascending
    // num[i] < num[i+1]
    for(int i = 0; i<= n-2; i++)
    {
        if(num[i] >= num[i+1]) 
        {
            flag = 0;
            break;
        }
    }
    // If they are ascending, check the diff between the numbers
    if(flag ==1)
    {
        for(int i = 0; i<= n-2; i++)
        {
            if(num[i+1] - num[i] > 3)
            {
                flag = 0;
            }
        }
    }

    int flag2 = 1;
    // Check if they are descending
    // num[i] > num[i+1]
    for(int i = 0; i<= n-2; i++)
    {
        if(num[i]<=num[i+1]) 
        {
            flag2 = 0;
            break;
        }
    }
    // If they are descending, check the diff between the numbers
    if(flag2 ==1)
    {
        for(int i = 0; i<= n-2; i++)
        {
            if(num[i] - num[i+1] > 3)
            {
                flag2 = 0;
                break;
            }
        }
    }

    if(flag || flag2 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int lines = 1000;
    
    int count = 0;
    while(lines--)
    {
        string input;
        getline(cin, input);
        if(isSafe(input)) count++;
    }
    cout<<count;
    return 0;
}
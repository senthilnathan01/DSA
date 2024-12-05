#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include <sstream>
#include<set>

using namespace std;

int main()
{
    unordered_map<int, set<int>> mpp;
    int rules = 1176;
    while(rules--)
    {
        string rule_string;
        cin>>rule_string;
        vector<int> numbers;
        stringstream ss(rule_string);
        string part;
        while(getline(ss, part, '|'))
        {
            numbers.push_back(stoi(part));
        }
        mpp[numbers[0]].insert(numbers[1]);
    }

    int sum = 0;
    int updates = 190;
    while(updates--)
    {
        string input;
        cin>>input;

        unordered_map<int, int> numberToIndex;
        stringstream ss(input);
        string part;
        vector<int> numbers;
        int index = 1;
        while (getline(ss, part, ',')) {
            int number = stoi(part);  // Convert to integer
            numberToIndex[number] = index++;  // Store the number and its index
            numbers.push_back(number);
        }
        int flag = 1;
        for(int number: numbers)
        {
            int index = numberToIndex[number];
            for(int num:mpp[number])
            {
                if(numberToIndex[num]!=0 && numberToIndex[num] < index)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0) break;
        }
        if(flag == 1)
        {
            // Get the middle number
            cout<<numbers[numbers.size()/2]<<endl;
            sum += numbers[numbers.size()/2];
        }
    }   
    cout<<sum;
}



#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>

using namespace std;

vector<vector<int>> generateBinaryVectors(int n) {
    vector<vector<int>> result;
    int totalVectors = 1 << n; // 2^n total vectors

    for (int i = 0; i < totalVectors; ++i) {
        vector<int> currentVector;
        for (int j = 0; j < n; ++j) {
            // Extract the j-th bit of i
            currentVector.push_back((i >> j) & 1);
        }
        result.push_back(currentVector);
    }
    return result;
}

int main()
{
    int lines = 850;
    long long int sum = 0;
    while(lines--)
    {
        string input;
        long long int num;
        getline(cin, input);
        vector<long long int> numbers;
        size_t colonPos = input.find(":");
        stringstream(input.substr(0, colonPos)) >> num;
        stringstream ss(input.substr(colonPos + 1));
        long long int temp;
        cout<<num<<endl;
        while (ss >> temp) {
            numbers.push_back(temp);
        }
        int n = numbers.size(); // We have n numbers
        // We have operations in n-1 positions
        vector<vector<int>> binaryVectors = generateBinaryVectors(n-1);

        for(auto vec: binaryVectors)
        {
            long long int ans = numbers[0];
            for(int operation_index = 0; operation_index<=n-2; operation_index++)
            {  
                if(vec[operation_index]==0) ans += numbers[operation_index+1];
                else ans *= numbers[operation_index+1];
            }
            if(num==ans)
            {
                sum += num;
                break;
            }
        }
    }
    cout<<sum;
}
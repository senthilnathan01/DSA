#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<typeinfo>

#define ull unsigned long long int
using namespace std;

vector<vector<int>> generateTernaryVectors(int n) {
    vector<vector<int>> result;
    int totalVectors = pow(3, n); // Total vectors = 3^n

    for (int i = 0; i < totalVectors; ++i) {
        vector<int> currentVector;
        int num = i; // Use num to generate the ternary equivalent

        for (int j = 0; j < n; ++j) {
            currentVector.push_back(num % 3); // Get the remainder (0, 1, or 2)
            num /= 3;                        // Move to the next digit in base-3
        }

        result.push_back(currentVector);
    }
    return result;
}

ull appendNumbers(ull a, ull b) {
    string a1 = to_string(a);
    string b1 = to_string(b);
    string combined = a1 + b1;
    ull answer = stoull(combined);
    return answer;
}

int main()
{
    int lines = 850;
    ull sum = 0;
    while(lines--)
    {
        string input;
        ull num;
        getline(cin, input);
        vector<ull> numbers;
        size_t colonPos = input.find(":");
        stringstream(input.substr(0, colonPos)) >> num;
        stringstream ss(input.substr(colonPos + 1));
        ull temp;
        cout<<num<<endl;
        while (ss >> temp) {
            numbers.push_back(temp);
        }
        int n = numbers.size(); // We have n numbers
        // We have operations in n-1 positions
        vector<vector<int>> ternaryVectors = generateTernaryVectors(n-1);

        for(auto vec: ternaryVectors)
        {
            ull ans = numbers[0];
            for(int operation_index = 0; operation_index<=n-2; operation_index++)
            {  
                if(vec[operation_index]==0) ans += numbers[operation_index+1];
                else if(vec[operation_index]==2) ans = appendNumbers(ans, numbers[operation_index+1]);
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
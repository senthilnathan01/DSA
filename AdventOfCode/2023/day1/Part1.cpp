#include<iostream>
#define CODE ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

void solve(int& sum)
{
    int testCases = 1000;
    for(int i = 0; i<testCases; i++)
    {
        string text;
        cin>>text;

        int first_digit, last_digit;

        for (int i = 0; i < text.length(); i++) {
            if (isdigit(text[i])) 
            {
                first_digit = text[i] - '0';
                break;
            }
        }

        for (int i = text.length() - 1; i >=0; i--) {
            if (isdigit(text[i])) 
            {
                last_digit = text[i] - '0';
                break;
            }
        }
        sum += (first_digit*10 + last_digit);
    }
}

int main()
{
    CODE
    int sum = 0;
    solve(sum);
    cout<<sum;
}








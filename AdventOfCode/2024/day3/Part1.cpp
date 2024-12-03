#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main()
{
    int lines = 6;
    string mainstring = "";
    while(lines --)
    {
        string linestring;
        getline(cin, linestring);
        mainstring += linestring;
    }
    regex pattern(R"(mul\((\d+),\s*(\d+)\))");
    smatch match;
    int sum = 0;

    string::const_iterator searchStart(mainstring.cbegin());
    while(regex_search(searchStart, mainstring.cend(), match, pattern))
    {
        int num1 = stoi(match[1].str());
        int num2 = stoi(match[2].str());

        sum += (num1*num2);
        searchStart = match.suffix().first;
    }
    cout<<sum;
    return 0;
}
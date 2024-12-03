#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {

    // Define the patterns
    regex mul_pattern(R"(mul\((\d+),(\d+)\))");
    regex do_pattern(R"(do\(\))");
    regex dont_pattern(R"(don't\(\))");

    string line;
    getline(cin, line);

    int sum = 0;

    auto it_do = line.cbegin();
    auto it_dont = line.cbegin();
    smatch match1, match2, match3;
    
    // Get the positions of dont and do
    vector<pair<int, int>> dontpositions;
    while(regex_search(it_dont, line.cend(), match1, dont_pattern))
    {
        it_dont += match1.position()+ match1.length();
        dontpositions.push_back({it_dont -7-line.cbegin(), 0});
    }

    vector<pair<int, int>> dopositions;
    while(regex_search(it_do, line.cend(), match2, do_pattern))
    {
        it_do += match2.position()+ match2.length();
        dopositions.push_back({it_do - 4 - line.cbegin(), 1});
    }


    vector<pair<int, int>> positions;
    positions.insert(positions.end(), dontpositions.begin(), dontpositions.end());
    positions.insert(positions.end(), dopositions.begin(), dopositions.end());
    sort(positions.begin(), positions.end());

    // Only check for mul_pattern after do_pattern and before dont_pattern
    // Get the range for which the mul_pattern should be checked
    vector<vector<int>> StartStop;
    int start = 0;
    int end = positions[0].first;
    StartStop.push_back({start, end});
    for(int i = 0; i<=positions.size()-2; i++)
    {
        if(positions[i].second==1 && (positions[i+1].second==1 || positions[i+1].second==0))
        {
            start = positions[i].first;
            int end = positions[i+1].first;
            StartStop.push_back({start, end});
        }
    }
    if(positions[positions.size()-1].second == 1) StartStop.push_back({positions[positions.size()-1].first, int(line.size())-1});
    if(StartStop.size()==0)
    {
        StartStop.push_back({0,int(line.size())-1});
    }

    for(auto range: StartStop)
    {
        int start = range[0], stop = range[1];
        auto it_mul = line.cbegin();
        it_mul += start;
        while(regex_search(it_mul, line.cbegin()+stop, match3, mul_pattern))
        {
            int num1 = std::stoi(match3[1].str());
            int num2 = std::stoi(match3[2].str());
            sum += num1 * num2;  
            it_mul += match3.position()+match3.length();
        }
    }
    
    cout<<sum;
}

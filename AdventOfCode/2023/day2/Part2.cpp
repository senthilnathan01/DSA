#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<regex>
#include <tuple>

using namespace std;

struct Game
{
    int red;
    int green;
    int blue;
};

Game processGames(string& input)
{
    // Given the string separate the sets and get the number of balls
    string revealedSet;
    stringstream ss(input);

    // Regex patterns for extracting counts of red, green, and blue
    regex redRegex(R"((\d+)\s*red)");
    regex greenRegex(R"((\d+)\s*green)");
    regex blueRegex(R"((\d+)\s*blue)");

    int red = 0, green = 0, blue = 0;
    while(getline(ss, revealedSet, ';'))
    {
        smatch match;

        // Search for red balls
        if (regex_search(revealedSet, match, redRegex)) {
            red = max(stoi(match[1]), red);
        }

        // Search for green balls
        if (regex_search(revealedSet, match, greenRegex)) {
            green = max(stoi(match[1]), green);
        }

        // Search for blue balls
        if (regex_search(revealedSet, match, blueRegex)) {
            blue = max(stoi(match[1]), blue);
        }
    }
    return {red, green, blue};
}

int main()
{
    int redMax = 12, greenMax = 13, blueMax = 14;
    int sum = 0;
    for(int i = 1; i<=100; i++)
    {
        string input;
        getline(cin, input);
        auto Games = processGames(input);
        sum += (Games.red*Games.green*Games.blue);
    }
    cout<<sum;
}
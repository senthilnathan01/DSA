/*
What is Regex?
Regular expressions (regex) are patterns used to match and manipulate text. Think of them as a powerful "find and replace" tool that can search for complex patterns, not just exact words.

Core Regex Functions in C++
There are three main functions you'll use:

std::regex_search() - finds if pattern exists anywhere in text
std::regex_match() - checks if entire string matches pattern
std::regex_replace() - replaces matched patterns
*/

#include <iostream>
#include <regex>
#include <string>

int main() {
    std::string text = "Hello world";
    std::regex pattern("world");
    
    // 1. regex_search - finds pattern anywhere in string
    if (std::regex_search(text, pattern)) {
        std::cout << "regex_search: Found 'world' somewhere in text" << std::endl;
    }
    
    // 2. regex_match - checks if ENTIRE string matches pattern
    if (std::regex_match(text, pattern)) {
        std::cout << "regex_match: Entire string is 'world'" << std::endl;
    } else {
        std::cout << "regex_match: Entire string is NOT 'world'" << std::endl;
    }
    
    // 3. regex_replace - replace matches with new text
    std::string result = std::regex_replace(text, pattern, "universe");
    std::cout << "regex_replace: " << result << std::endl;
    
    return 0;
}

/*
regex_search: Found 'world' somewhere in text
regex_match: Entire string is NOT 'world'
regex_replace: Hello universe
*/

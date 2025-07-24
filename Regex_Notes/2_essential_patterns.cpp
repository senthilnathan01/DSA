#include <iostream>
#include <regex>
#include <string>

void testPattern(const std::string& text, const std::string& pattern, const std::string& description) {
    std::regex reg(pattern);
    std::cout << description << ": ";
    if (std::regex_search(text, reg)) {
        std::cout << "MATCH";
    } else {
        std::cout << "NO MATCH";
    }
    std::cout << std::endl;
}

int main() {
    std::string text = "Hello123 World! @#$";
    
    std::cout << "Testing with: \"" << text << "\"" << std::endl << std::endl;
    
    // 1. Literal characters - exact match
    testPattern(text, "Hello", "Literal 'Hello'");
    testPattern(text, "hello", "Literal 'hello' (case sensitive)");
    
    // 2. Dot (.) - matches any single character
    testPattern(text, "H.llo", "H.llo (. matches any char)");
    testPattern(text, "Wor.d", "Wor.d");
    
    // 3. Character classes
    testPattern(text, "[0-9]", "[0-9] (any digit)");
    testPattern(text, "[a-z]", "[a-z] (any lowercase letter)");
    testPattern(text, "[A-Z]", "[A-Z] (any uppercase letter)");
    testPattern(text, "[!@#$]", "[!@#$] (any of these symbols)");
    
    // 4. Predefined character classes
    testPattern(text, "\\d", "\\d (any digit - same as [0-9])");
    testPattern(text, "\\w", "\\w (any word character: letter, digit, _)");
    testPattern(text, "\\s", "\\s (any whitespace)");
    
    return 0;
}

/*
Testing with: "Hello123 World! @#$"

Literal 'Hello': MATCH
Literal 'hello' (case sensitive): NO MATCH
H.llo (. matches any char): MATCH
Wor.d: MATCH
[0-9] (any digit): MATCH
[a-z] (any lowercase letter): MATCH
[A-Z] (any uppercase letter): MATCH
[!@#$] (any of these symbols): MATCH
\d (any digit - same as [0-9]): MATCH
\w (any word character: letter, digit, _): MATCH
\s (any whitespace): MATCH
*/

/*
Anchors:
Anchors specify where in the string to match:
Think of anchors as "location requirements":

^ = "must be at the start" (like a capital letter at sentence start)
$ = "must be at the end" (like a period at sentence end)
\b = "must be at a word boundary" (like spaces around words)
*/

#include <iostream>
#include <regex>
#include <string>

void testAnchor(const std::string& text, const std::string& pattern, const std::string& description) {
    std::regex reg(pattern);
    std::cout << description << " in \"" << text << "\": ";
    if (std::regex_search(text, reg)) {
        std::cout << "MATCH";
    } else {
        std::cout << "NO MATCH";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== ANCHORS ===" << std::endl << std::endl;
    
    std::string text1 = "hello world";
    std::string text2 = "world hello";
    std::string text3 = "say hello to the world";
    
    // ^ means "start of string"
    std::cout << "Testing ^ (start of string):" << std::endl;
    testAnchor(text1, "^hello", "^hello");
    testAnchor(text2, "^hello", "^hello");
    testAnchor(text3, "^hello", "^hello");
    std::cout << std::endl;
    
    // $ means "end of string"
    std::cout << "Testing $ (end of string):" << std::endl;
    testAnchor(text1, "world$", "world$");
    testAnchor(text2, "world$", "world$");
    testAnchor(text3, "world$", "world$");
    std::cout << std::endl;
    
    // \\b means "word boundary"
    std::cout << "Testing \\b (word boundary):" << std::endl;
    std::string text4 = "cat catch cats";
    testAnchor(text4, "\\bcat\\b", "\\bcat\\b (whole word 'cat')");
    testAnchor(text4, "cat", "cat (anywhere)");
    
    return 0;
}

/*
=== ANCHORS ===

Testing ^ (start of string):
^hello in "hello world": MATCH
^hello in "world hello": NO MATCH
^hello in "say hello to the world": NO MATCH

Testing $ (end of string):
world$ in "hello world": MATCH
world$ in "world hello": NO MATCH
world$ in "say hello to the world": MATCH

Testing \b (word boundary):
\bcat\b (whole word 'cat') in "cat catch cats": MATCH
cat (anywhere) in "cat catch cats": MATCH
*/

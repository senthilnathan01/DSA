/*
Quantifiers tell regex how many times to match a pattern:

* = "I'll eat zero or more" (not picky)
+ = "I need at least one" (a bit picky)
? = "I'm optional" (take it or leave it)
{3} = "I want exactly 3" (very specific)
{2,5} = "I want between 2 and 5" (flexible within limits)
*/

#include <iostream>
#include <regex>
#include <string>

void findMatches(const std::string& text, const std::string& pattern, const std::string& description) {
    std::regex reg(pattern);
    std::sregex_iterator start(text.begin(), text.end(), reg);
    std::sregex_iterator end;
    
    std::cout << description << " in \"" << text << "\":" << std::endl;
    
    bool found = false;
    for (std::sregex_iterator i = start; i != end; ++i) {
        std::smatch match = *i;
        std::cout << "  Found: '" << match.str() << "' at position " << match.position() << std::endl;
        found = true;
    }
    
    if (!found) {
        std::cout << "  No matches found" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Test different quantifiers
    std::cout << "=== QUANTIFIERS ===" << std::endl << std::endl;
    
    // * means "zero or more"
    findMatches("aaa bb cccc d", "a*", "a* (zero or more 'a')");
    findMatches("hello hllo hlo ho", "he*llo", "he*llo (zero or more 'e')");
    
    // + means "one or more"
    findMatches("aaa bb cccc d", "a+", "a+ (one or more 'a')");
    findMatches("123 45 6789", "\\d+", "\\d+ (one or more digits)");
    
    // ? means "zero or one" (optional)
    findMatches("color colour", "colou?r", "colou?r (optional 'u')");
    
    // {n} means "exactly n times"
    findMatches("123 45 6789", "\\d{3}", "\\d{3} (exactly 3 digits)");
    
    // {n,m} means "between n and m times"
    findMatches("a aa aaa aaaa", "a{2,3}", "a{2,3} (2 to 3 'a's)");
    
    return 0;
}
/*
=== QUANTIFIERS ===


a* (zero or more 'a') in "aaa bb cccc d":
  Found: 'aaa' at position 0
  Found: '' at position 3
  Found: '' at position 4
  Found: '' at position 5
  Found: '' at position 6
  Found: '' at position 7
  Found: '' at position 8
  Found: '' at position 9
  Found: '' at position 10
  Found: '' at position 11
  Found: '' at position 12
  Found: '' at position 13


he*llo (zero or more 'e') in "hello hllo hlo ho":
  Found: 'hello' at position 0
  Found: 'hllo' at position 6


a+ (one or more 'a') in "aaa bb cccc d":
  Found: 'aaa' at position 0


\d+ (one or more digits) in "123 45 6789":
  Found: '123' at position 0
  Found: '45' at position 4
  Found: '6789' at position 7


colou?r (optional 'u') in "color colour":
  Found: 'color' at position 0
  Found: 'colour' at position 6


\d{3} (exactly 3 digits) in "123 45 6789":
  Found: '123' at position 0
  Found: '678' at position 7


a{2,3} (2 to 3 'a's) in "a aa aaa aaaa":
  Found: 'aa' at position 2
  Found: 'aaa' at position 5
  Found: 'aaa' at position 9
*/

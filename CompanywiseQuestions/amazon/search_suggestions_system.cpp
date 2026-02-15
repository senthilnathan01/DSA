/*
You are given an array of strings products and a string searchWord.

Design a system that suggests at most three product names from products after each character of searchWord is typed. 
Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.

Return a list of lists of the suggested products after each character of searchWord is typed.

LINK: https://leetcode.com/problems/search-suggestions-system/description/ 
*/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        string prefix = "";
        vector<vector<string>> ans;

        for(char c: searchWord){
            prefix += c;
            vector<string> toAdd;

            auto it = lower_bound(products.begin(), products.end(), prefix);
            // Get the next three elements using i
            for(int i = 0; i < 3 && it + i != products.end(); i++){
                string candidate = *(it+i);
                if(candidate.substr(0, prefix.size())==prefix) toAdd.push_back(candidate);
                else break;
            }
            ans.push_back(toAdd);
        }
        return ans;
    }
};

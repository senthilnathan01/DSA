/*
You are given an array of logs. Each log is a space-delimited string of words, where the first word is the identifier.

There are two types of logs:

Letter-logs: All words (except the identifier) consist of lowercase English letters.
Digit-logs: All words (except the identifier) consist of digits.
Reorder these logs so that:

The letter-logs come before all digit-logs.
The letter-logs are sorted lexicographically by their contents. If their contents are the same, then sort them lexicographically by their identifiers.
The digit-logs maintain their relative ordering.
Return the final order of the logs.

LINK: https://leetcode.com/problems/reorder-data-in-log-files/description/
*/  

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string &a,const string &b){
            int posA = a.find(' ');
            int posB = b.find(' ');

            string idA = a.substr(0, posA);
            string idB = b.substr(0, posB);

            string contentA = a.substr(posA+1);
            string contentB = b.substr(posB+1);

            bool isDigitA = isdigit(contentA[0]);
            bool isDigitB = isdigit(contentB[0]);

            // Rules: 
            //1. letter comes before digits
            //2. if both are letters sort them
            //3. otherwise leave the order as it it

            // 2.
            if(!isDigitA && !isDigitB){
                if(contentA==contentB) return idA < idB;
                else return contentA < contentB;
            }
            //1.
            else if(!isDigitA && isDigitB) return true;
            else if(isDigitA && !isDigitB) return false;
            // 3.
            return false;
        });

        return logs;
    }
};

// Instead of using stable_sort to ensure relative ordering of digit logs
// We could have separated them out first before sorting letter logs
// And just append them to the answer list at the end of the sorting process
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letter_logs;
        vector<string> digit_logs;

        // Separate out digit logs
        for(auto log: logs){
            int pos = log.find(' ');
            if(isdigit(log[pos+1])) digit_logs.push_back(log);
            else letter_logs.push_back(log);
        }

        // Sort letter logs
        sort(letter_logs.begin(), letter_logs.end(), [](const string &a,const string &b){
            int posA = a.find(' ');
            int posB = b.find(' ');

            string idA = a.substr(0, posA);
            string idB = b.substr(0, posB);

            string contentA = a.substr(posA+1);
            string contentB = b.substr(posB+1);

            if(contentA == contentB) return idA < idB;
            
            return contentA < contentB;
        });

        letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());
        return letter_logs;
    }
};

/*
A boolean expression is an expression that evaluates to either true or false. It can be in one of the following shapes:

't' that evaluates to true.
'f' that evaluates to false.
'!(subExpr)' that evaluates to the logical NOT of the inner expression subExpr.
'&(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical AND of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
'|(subExpr1, subExpr2, ..., subExprn)' that evaluates to the logical OR of the inner expressions subExpr1, subExpr2, ..., subExprn where n >= 1.
Given a string expression that represents a boolean expression, return the evaluation of that expression.

It is guaranteed that the given expression is valid and follows the given rules.

LINK: https://leetcode.com/problems/parsing-a-boolean-expression/description/
*/

// String Manipulation
class Solution {
public:
    bool parseBoolExpr(string expression) {
        while(expression.length()>1){
            int start = expression.find_last_of("!&|");
            int end = expression.find(')', start);
            string subExpr = expression.substr(start, end - start + 1);
            char result = evaluateSubExpr(subExpr);
            expression.replace(start, end - start + 1, 1, result);
        }
        return expression[0] == 't';
    }

private:
    char evaluateSubExpr(const string &subExpr){
        char op = subExpr[0];
        string values = subExpr.substr(2, subExpr.length()-3);

        if(op == '!') return values[0] == 't'?'f':'t';
        if(op == '&') return values.find('f')!=string::npos ? 'f':'t';
        if(op == '|') return values.find('t')!=string::npos ? 't':'f';
        return 'f'; // This point will not be reached as per the question
    }
};

// Recursive
class Solution {
public:
    bool parseBoolExpr(string expression) {
        int index = 0;
        return evaluate(expression, index);
    }

private:
    bool evaluate(string &expr, int &index){
        char currChar = expr[index++];

        if(currChar == 't') return true;
        if(currChar == 'f') return false;

        // NOT Operation
        if(currChar == '!'){
            index++; // Skip '('
            bool result = !evaluate(expr, index);
            index++;
            return result;
        }

        // Preparing for AND and OR
        // Collect results of subexpressions
        vector<bool> values;
        index++; // Skip '('
        while(expr[index]!=')'){
            if(expr[index]!=','){
                values.push_back(evaluate(expr, index))
            }
            else{
                index++;
            }
        }
        index++;

        // AND Operation
        if(currChar == '&'){
            for(bool v: values) if(!v) return false;
            return true;
        }

        // OR Operation
        if(currChar == '|'){
            for(bool v: values) if(v) return true;
            return false;
        }

        return false; // This point wont be reached


        
    }
};

// Using Stack
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char currChar: expression){
            if(currChar == ')'){
                vector<char> values;

                while(st.top()!='('){
                    values.push_back(st.top());
                    st.pop();
                }
                st.pop(); // Remove '('
                char op = st.top();
                st.pop(); // Remove the operator

                // Evaluate the subexpression and push the result to stack
                char result = evaluateSubExpr(op, values);
                st.push(result);
            }
            else if(currChar != ','){
                st.push(currChar);
            }
        }

        return st.top() == 't';
    }

private:
    char evaluateSubExpr(char op, vector<char> &values){
        // NOT
        if(op=='!') return values[0] == 't' ? 'f':'t';

        // AND
        if(op=='&'){
            for(char value: values) if(value == 'f') return 'f';
            return 't';
        }

        // OR
        if(op=='|'){
            for(char value: values) if(value == 't') return 't';
            return 'f';
        }

        return 'f'; // This point should never be reached
    }
};

// Optimised Stack
// Just need not read all the bools and evaluate
// For example, if one true is present -> OR will result in true
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char currChar: expression){
            if(currChar == ',' || currChar == '(') continue;
            
            if(currChar == ')'){
                bool hasTrue = false, hasFalse = false;

                while(st.top() == 't' || st.top()=='f'){
                    char topVal = st.top();
                    st.pop();
                    if(topVal=='t') hasTrue = true;
                    if(topVal=='f') hasFalse = true;
                }

                char op = st.top();
                st.pop();
                if(op=='!') st.push(hasTrue ? 'f':'t');
                else if(op=='&') st.push(hasFalse ? 'f':'t');
                else st.push(hasTrue ? 't':'f');
            }
            else{
                st.push(currChar);
            }
        }

        return st.top() == 't';
    }
};

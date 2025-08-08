/*
Tricky Parts and how we are going to solve them:

1. Note that a number can contain multiple digits.

We can take care of this by adding one more operator
Operator = appending it to the prev number

OR
Instead of an operator
we can select a substring (with length ranging from 1 to end of the num) everytime

---
So we have 4 operations in total

Total time complexity = 4^(n-1)
---

2. * operator
For addition and subtraction, you just add/subtract the next operand.
For multiplication:
>subtract prev operand from val
>Add (prev operand * currentOperand) instead
>Thus we need to keep track of the previous operand

3. Note that operands in the returned expressions should not contain leading zeros.
It is straight forward...like...it is for their convenience...just don't continue with such operands
Look at the code to understand better
*/

class Solution {
public:
    vector<string> ans;

    void backtrack(int idx, long long prevNum, long long tot, string &expr, const string &num, long long target) {
        if (idx == num.size()) {
            if (tot == target) ans.push_back(expr);
            return;
        }

        long long val = 0;
        int lenBefore = expr.size();

        for (int i = idx; i < num.size(); i++) {
            // Skip numbers with leading zeros
            if (i > idx && num[idx] == '0') break;

            // Build number incrementally
            val = val * 10 + (num[i] - '0');
            if (val > LLONG_MAX) break; // overflow guard

            if (idx == 0) {
                // First number, no operator
                expr.append(num, idx, i - idx + 1);
                backtrack(i + 1, val, val, expr, num, target);
                expr.resize(lenBefore);
            } else {
                // Addition
                expr.push_back('+');
                expr.append(num, idx, i - idx + 1);
                backtrack(i + 1, val, tot + val, expr, num, target);
                expr.resize(lenBefore);

                // Subtraction
                expr.push_back('-');
                expr.append(num, idx, i - idx + 1);
                backtrack(i + 1, -val, tot - val, expr, num, target);
                expr.resize(lenBefore);

                // Multiplication
                expr.push_back('*');
                expr.append(num, idx, i - idx + 1);
                backtrack(i + 1, prevNum * val, tot - prevNum + prevNum * val, expr, num, target);
                expr.resize(lenBefore);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        string expr;
        expr.reserve(num.size() * 2); // pre-allocate to avoid reallocations
        backtrack(0, 0, 0, expr, num, static_cast<long long>(target));
        return ans;
    }
};

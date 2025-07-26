/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Leetcode Link: https://leetcode.com/problems/min-stack/description/
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// Solution 1:
// Brute Force
// We look through the stack to find the min element 
class MinStack {
public:
    stack <int> st;
    MinStack() {
        // Nothing is necessary
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {    
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        // Now we gotta do length ass operation
        // We talking about brute force now
        int minVal = st.top(); // Initialise
        // Let's check the numbers in stack one by one
        // We will be popping them out
        // remember to keep them all in place again
        // For this we gotta store the numbers in the proper order
        // Let's have another temp stack for that
        stack<int> temp;
        while(!st.empty())
        {
            minVal = min(minVal, st.top());
            temp.push(st.top());
            st.pop();
        }
        // st is empty now
        // put the numbers in place again
        while(!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }

        return minVal;
    }
};

// Solution 2:
// We always maintain a stack with minimum elements obtained so far
// During push and pop we update the stack accordingly
// While calling to get the min element we directly return that stack's top element
class MinStack {
public:
    stack <int> st;
    stack <int> minSt;
    MinStack() {
        // Nothing is necessary
    }
    
    void push(int val) {
        st.push(val);
        minSt.push(min(val, minSt.empty() ? val: minSt.top()));
    }
    
    void pop() {    
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

// Solution 3:
// Why do we need to maintain another separate stack?
// It occupies space. While retrieving we are going to retrieve the top element only
// So always maintain a number called min number, update them during push and pop
// Just return that value when called for min element
// Some modification needs to made on how the values are stored in the stack to do this
// Thus while calling top() also we need to take care to return the value after modifying
// The modification: See the code u will understand. Try doing a dry run, u will understand.
class MinStack {
private:
    long min;
    std::stack<long> stack;

public:
    MinStack() {}
    
    void push(int val) {
        if (stack.empty()) {
            stack.push(0);
            min = val;
        } else {
            stack.push(val - min);
            if (val < min) min = val;
        }
    }
    
    void pop() {
        if (stack.empty()) return;
        
        long pop = stack.top();
        stack.pop();
        
        if (pop < 0) min = min - pop;
    }
    
    int top() {
        long top = stack.top();
        return (top > 0) ? (top + min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};
// Here we maintain in long cuz the addition and subtraction to the original may go out of bounds

// Solution 4:
// Best solution for me is to store a pair<int, int> in the stack
// The second always maintains the min value obtained till that point
// When top is called return .first
// When min element is called return .second
// Simple!
class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) 
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, min(val, st.top().second)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};


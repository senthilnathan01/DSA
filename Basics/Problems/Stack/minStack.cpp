#include<iostream>
#include<stack>

using namespace std;

/*
Problem:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

// TC = O(1)
// SC = O(2N)
class MinStack {
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x,min});
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

// Better Approach:
// TC = O(1)
// SC = O(N)
class MinStack2
{
    stack<int> st;
    int minNum = INT16_MAX;
    void push(int val)
    {
        if(st.empty())
        {
            int minNum = val;
            st.push(val);
        }
        else
        {
            if(val >= minNum) st.push(val);
            else
            {
                st.push(2*val - minNum);
                minNum = val;
            }
        }
    }

    void pop()
    {
        if(st.empty()) return;
        
        int x = st.top();
        st.pop();
        if(x<minNum)
        {
            minNum = 2*minNum - x;
        }
    }

    int top()
    {
        if(st.empty()) return -1;
        int x = st.top();
        if(x < minNum) return minNum;
        else return x;
    }

    int getMin()
    {
        return minNum;
    }
};

int main()
{
    return 0;
}

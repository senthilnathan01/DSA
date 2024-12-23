#include<iostream>
#include<stack>

using namespace std;

class Queue
{
    stack<int> input, output;
    public:
        void Push(int data)
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            input.push(data);
            while(!output.empty())
            {
                input.push(output.top());
                output.pop();
            }
        }

        int Pop()
        {
            int val = input.top();
            input.pop();
            return val;
        }

        int Top()
        {
            return input.top();
        }

        int Size()
        {
            return input.size();
        }
};


int main()
{
    // Let's try our implementation
    Queue q;
    q.Push(3);
    q.Push(4);
    cout<<q.Size()<<endl;
    cout<<q.Pop()<<endl;
    cout<<q.Top()<<endl;
    q.Push(5);
    cout<<q.Top()<<endl;
    cout<<q.Size();
}

// OUTPUT:
// 2
// 3
// 4
// 4
// 2


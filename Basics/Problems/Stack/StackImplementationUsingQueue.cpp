#include<iostream>
#include<queue>

using namespace std;

class Stack
{
    queue<int> q;
    public:
        void Push(int x)
        {
            int s = q.size();
            q.push(x);
            for(int i = 0; i < s; i++)
            {
                q.push(q.front());
                q.pop();
            }
        }
    
    int Pop()
    {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int Top()
    {
        return q.front();
    }

    int Size()
    {
        return q.size();
    }
};


int main()
{
    // Let's try our implementation
    Stack s;
    s.Push(3);
    s.Push(2);
    s.Push(4);
    s.Push(1);
    cout<<s.Top()<<endl;
    cout<<s.Size()<<endl;
    cout<<s.Pop()<<endl;
    cout<<s.Top()<<endl;
    cout<<s.Size()<<endl;
    
    return 0;   
}

// OUTPUT:
// 1
// 4
// 1
// 4
// 3


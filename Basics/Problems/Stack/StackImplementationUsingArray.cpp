#include<iostream>

using namespace std;

// Stack behind the scenes LOL
// (Without considering the edge cases (just for simplicity of viewing))
class Stack
{
    int size;
    int *arr;
    int top;
    public:
    Stack()
    {
        top = -1;
        size = 1000;
        arr = new int[size];
    }

    void Push(int x)
    {
        top++;
        arr[top] = x;
    }

    int Pop()
    {
        int x = arr[top];
        top--;
        return x;
    }

    int Top()
    {
        return arr[top];
    }

    int Size()
    {
        return top+1;
    }
};

int main()
{
    // Let's try out implementation of Stack
    Stack s;
    s.Push(6);
    s.Push(3);
    cout<<s.Size()<<endl;
    cout<<s.Top()<<endl;
    cout<<s.Size()<<endl;
    cout<<s.Pop()<<endl;
    cout<<s.Size()<<endl;
    cout<<s.Top()<<endl;

    return 0;   
}

// OUTPUT:
// 2
// 3
// 2
// 3
// 1
// 6
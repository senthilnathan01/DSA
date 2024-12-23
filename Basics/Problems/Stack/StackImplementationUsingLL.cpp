#include<iostream>

using namespace std;

// Linked List Structure
struct stackNode
{
    int data;
    stackNode *next;
    size_t size;
    stackNode(int x)
    {
        data = x;
        next = NULL;
    }
};

class Stack
{
    stackNode * top;
    size_t size;
    public:
        Stack()
        {
            top = NULL;
            size = 0;
        }

        void Push(int x)
        {
            stackNode * element = new stackNode(x);
            element -> next = top;
            top = element;
            size++;
        }
        
        int Pop()
        {
            if(top==NULL) return -1;
            int topData = top->data;
            stackNode *temp = top;
            top = top->next;
            delete temp;
            size--;
            return topData;
        }

        int Size()
        {
            return size;
        }

        bool isEmpty() 
        {
            return top == NULL;
        }

        int Top()
        {
            return top->data;
        }

        void printStack()
        {
            stackNode *current = top;
            while(current != NULL)
            {
                cout<<current->data<<" ";
                current = current->next;
            }
        }
};

int main()
{
    Stack s;
    s.Push(10);
    cout<<s.Size()<<endl;
    cout<<s.Top()<<endl;
    cout<<s.Pop()<<endl;
    cout<<s.Size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}

// OUTPUT:
// 1
// 10
// 10
// 0
// 1

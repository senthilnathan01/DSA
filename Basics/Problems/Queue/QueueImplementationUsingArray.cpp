#include<iostream>

using namespace std;

// Queue behind the scenes LOL
// (Without considering the edge cases (just for simplicity of viewing))
class Queue
{
    int *arr;
    int start, end, currSize, maxSize;
    public:
        Queue()
        {
            arr = new int[16];
            start = -1;
            end = -1;
            currSize = 0;        
        }
    
    Queue(int maxSize)
    {
        (*this).maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }

    void push(int newElement)
    {
        if(currSize==maxSize)
        {
            cout<<"Queue is full\nExiting..."<<endl;
            exit(1);
        }
        else
        {
            if(end==-1)
            {
                start = 0;
                end = 0;
            }
            else
            {
                end = (end+1)%maxSize;
            }
            arr[end] = newElement;
            currSize++;
        }
    }

    int pop()
    {
        if(start == -1)
        {
            cout<<"Queue Empty"<<endl;
        }
        else
        {
            int popped = arr[start];
            if(currSize==1)
            {
                start = -1;
                end = -1;
            }
            else
            {
                start = (start+1)%maxSize;
                currSize--;
            }
            return popped;
        }
    }

    int top()
    {
        if(start == -1)
        {
            cout<<"Queue is empty"<<endl;
            exit(1);
        }
        return arr[start];
    }

    int size()
    {
        return currSize;
    }

};

int main()
{
    // Let's try out implementation of Queue
    Queue q(6);
    q.push(1);
    q.push(2);
    q.push(10);
    q.push(7);
    cout<<"Top element: "<<q.top()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    cout<<"Removed element: "<<q.pop()<<endl;
    cout<<"Top element: "<<q.top()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    
    return 0;   
}

// OUTPUT:
// Top element: 1
// Size: 4
// Removed element: 1
// Top element: 2
// Size: 3

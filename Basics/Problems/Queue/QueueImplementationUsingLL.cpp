#include<iostream>

using namespace std;

// Linked List Structure
struct queueNode
{   
    int data;
    queueNode *next;
    queueNode(int x)
    {
        data = x;
        next = NULL;
    }
};

class Queue
{
    queueNode *Front=NULL, *Rare = NULL;
    public:
    size_t size = 0;
    bool Empty();
    void Enqueue(int value);
    int Dequeue();
    int Peek();
};

bool Queue::Empty()
{
    return Front == NULL;
}

int Queue::Peek()
{
    return Front->data;
}

void Queue::Enqueue(int x)
{
    queueNode *temp;
    temp = new queueNode(x);
    
    if(Front == NULL)
    {
        Front = temp;
        Rare = temp;
    }
    else
    {
        Rare -> next = temp;
        Rare = temp;
    }
    size++;
}

int Queue::Dequeue()
{
    int toReturn = Front->data;
    queueNode *temp = Front;
    Front = Front->next;
    delete temp;
    size--;
    return toReturn;
}

int main()
{
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    cout<<q.size<<endl;
    cout<<q.Dequeue()<<endl;
    cout<<q.Peek()<<endl;
    cout<<q.size<<endl;
    return 0;
}

// OUTPUT:
// 2
// 10
// 20
// 1




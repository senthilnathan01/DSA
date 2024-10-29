#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* array2LL(vector<int>& arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i< arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

Node* removeHead(Node* head)
{
    /*
    INPUT: Current head
    The function deletes the current head and
    OUTPUTS: New head
    */
    if(head == NULL) return head;
   Node* temp = head;
   head = head -> next;
   delete temp;
   return head;
}


int main()
{
    vector<int> arr = {1,2,3,4};
    Node* head = array2LL(arr);
    head = removeHead(head);
    cout<<head->data;
}

// OUTPUT:
// 2

#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* createDLL(vector<int>& arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* InsertHead(Node* head, int val)
{   
    Node* newHead = new Node(val, head, NULL);
    head->back = NULL;
    return newHead;
}

int main()
{
    vector<int> arr= {1,3, 5, 10};
    Node* head = createDLL(arr);
    printLinkedList(head);
    Node* newHead = InsertHead(head, 9);
    printLinkedList(newHead);
}

// OUTPUT:
// 1 3 5 10 
// 9 1 3 5 10 

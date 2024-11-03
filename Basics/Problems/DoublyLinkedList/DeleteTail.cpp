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

Node* DeleteTail(Node* head)
{   
    if(head == NULL || head->next==NULL) return NULL;

    Node* temp = head;
    while(temp->next)
    {
        temp = temp->next;
    }

    Node* newTail = temp->back;
    newTail->next = NULL;
    temp->back = NULL;
    delete temp;
    return head;
}

int main()
{
    vector<int> arr= {1,3, 5, 10};
    Node* head = createDLL(arr);
    printLinkedList(head);
    head = DeleteTail(head);
    printLinkedList(head);
}

// OUTPUT:
// 1 3 5 10 
// 1 3 5

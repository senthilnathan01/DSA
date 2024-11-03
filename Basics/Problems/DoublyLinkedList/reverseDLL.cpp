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

Node* reverseDLL(Node* head)
{
    if(head==NULL || head->next==NULL) return head;

    Node* prev = NULL;
    Node* current = head;

    while(current)
    {
        current->back = current->next;
        current->next = prev;
        prev = current;
        current = current->back;        
    }
    return prev;
}

int main()
{
    vector<int> arr= {1,3, 5, 10};
    Node* head = createDLL(arr);
    printLinkedList(head);
    head = reverseDLL(head);
    printLinkedList(head);
}

// OUTPUT:
// 1 3 5 10 
// 10 5 3 1
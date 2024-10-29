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

Node* createLinkedList(vector<int>& arr)
{
    Node* head = nullptr;
    for (int i = arr.size() - 1; i >= 0; --i) {
        head = new Node(arr[i], head);
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

void insertAtEnd(Node *head, int x) {
    Node* tail = new Node(x);
    if(head == NULL) head = tail;
    else{
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp -> next = tail;
    }
}

int main()
{
    vector<int> arr = {1,2,3,4};
    Node* head = createLinkedList(arr);
    insertAtEnd(head, 5);
    printLinkedList(head);
}

// OUTPUT:
// 1 2 3 4 5 



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

void insertBeforeElement(Node*& head, int val, int el)
{
    if(head == NULL) return;
    Node* temp = head;
    Node* current = temp;
    while(temp)
    {
        if(temp->data == el)
        {
            current->next = new Node(val, temp);
            return;
        }
        current = temp;
        temp = temp->next;
    }
}

int main()
{
    vector<int> arr = {1,5,3,4};
    Node* head = createLinkedList(arr);
    insertBeforeElement(head, 10, 3);
    printLinkedList(head);
    insertBeforeElement(head, 10, 4);
    printLinkedList(head);
}

// OUTPUT:
// 1 5 10 3 4
// 1 5 10 3 10 4



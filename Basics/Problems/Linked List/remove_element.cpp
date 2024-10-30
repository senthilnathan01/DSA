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

void removeElement(Node* head, int k)
{
    if(head == NULL) return;
    if(head->data == k)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    Node* current = temp;
    while(temp)
    {
        if(temp->data == k)
        {
            current->next = temp->next;
            delete temp;
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
    removeElement(head, 3);
    printLinkedList(head);
}

// OUTPUT:
// 1 5 4



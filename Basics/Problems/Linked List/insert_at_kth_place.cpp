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

void insertAtKthPlace(Node*& head, int val, int k)
{
    if(k==1)
    {
        Node* newHead = new Node(k, head);
        head = newHead;
        return;
    }
    int count = 0;
    Node* temp = head;
    while(temp)
    {
        count++;
        if(count == k-1)
        {
            temp->next = new Node(val, temp->next);
            return;
        }
        temp = temp->next;
    }
}

int main()
{
    vector<int> arr = {1,5,3,4};
    Node* head = createLinkedList(arr);
    insertAtKthPlace(head, 10, 3);
    printLinkedList(head);
}

// OUTPUT:
// 1 5 10 3 4



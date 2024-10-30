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

// Brute Force Method:

Node* middleNode1(Node* head) {
    int length = 0;
    Node* temp = head;
    while(temp)
    {
        length++;
        temp = temp->next;
    }
    int middle = length/2 + 1;
    int count = 0;
    temp = head;
    while(temp)
    {
        count++;
        if(count == middle) return temp;
        temp = temp->next;
    }
    return NULL;
}

// Optimal Approach
Node* middleNode2(Node* head) {
    if(head == NULL) return head;
    Node* fast = head;
    Node* slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    vector<int> arr = {1,5,3,4};
    Node* head = createLinkedList(arr);
    printLinkedList(middleNode1(head));
    printLinkedList(middleNode2(head));
}

// OUTPUT:
// 3 4
// 3 4




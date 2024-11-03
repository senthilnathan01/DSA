#include<iostream>
#include<vector>
#include<map>

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

// Naive Approach
// TC = O(N*2*logN)
// First N for traversing the LL 
// 2*logN for inserting and checking the map

// SC= O(N) for map

bool hasCycle(Node *head) {
    Node* temp = head;
    map<Node*, int> mpp;
    while(temp)
    {
        if(mpp.find(temp)!=mpp.end()) return true;
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

// Optimal Approach
// TC = O(N)
// SC = O(1)

// Tortoise and Hare Algorithm

bool hasCycle(Node *head) {
    auto slow = head;
    auto fast = head;

    while(fast != NULL && fast->next !=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}




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

// Approach 1:
// Use hashing to stores the nodes. 
// Return the node which is was already traversed before (done by searching if that node is already in the map)

Node* StartingPoint(Node* head)
{
    Node* temp = head;
    map<Node*, int> mpp;
    while(temp && temp->next)
    {
        mpp[temp]=1;
        temp = temp->next;
        if(mpp[temp]==1) return temp;
    }
    return nullptr;    
}

// Approach 2:
// Make sure there is a loop in the LL using tortoise and hare algo
// And then find the starting point using the collision point in the before used algo

Node* StartingPoint2(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        {
            slow = head;
            if(slow==fast) return slow;
            while(slow!=fast)
            {
                slow = slow->next;
                fast = fast->next;
                if(slow==fast) return slow;
            }
        }
    }
    return NULL;
}





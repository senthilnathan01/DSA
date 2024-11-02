#include<iostream>
#include<vector>
#include<stack>

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

// Brute Force Approach using stack:
// TC = O(2N)
// SC = O(N)
Node* reverseList1(Node* head)
{
    stack<int> st;
    // Step 1: Add all the elements to the stack
    Node* temp = head;
    while(temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    
    // Step 2: Remove elements from the stack and edit the LL elements' value
    temp = head;
    while(temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;    
} 

// Optimal Approach:
// Just change the direction of the pointers using an iterative process
// TC = O(N)
// SC = O(1)

Node* reverseList2(Node* head)
{
    if(head == NULL || head->next == NULL) return head;
    
    // Step 0: Set the nodes in position
    Node* prev = nullptr;
    Node* temp = head;
    Node* front = temp->next;

    // Step 1: Change the link
    temp->next = prev;

    // Step 2: Reassign the positions
    prev = temp;
    temp = front;

    while(temp->next)
    {
        // Step 2 contd.
        front = temp->next;

        // Step 1: Change the link
        temp->next = prev;

        // Step 2: Reassign the positions
        prev = temp;
        temp = front;
    }
    temp->next = prev;
    return temp;
}

// Same approach using recursive process
Node* reverseUsingRecursion(Node* head)
{
    // base case
    if(head == NULL || head->next == NULL) return head;

    Node* newHead = reverseUsingRecursion(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    vector<int> arr = {1,5,3,4};
    Node* head = createLinkedList(arr);
    head = reverseList1(head);
    printLinkedList(head);
    head = reverseList2(head);
    printLinkedList(head);
    head = reverseUsingRecursion(head);
    printLinkedList(head);
}

// OUTPUT:
// 4 3 5 1
// 1 5 3 4 (Because we reversed in the previous step we get the original LL by reversing it again)
// 4 3 5 1


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

// 2 Approaches:

// 1st Approach (Brute Force):
// Create an empty stack. 
// This stack will be used to temporarily store the nodes from the original linked list as we traverse it.
// Set variable `temp` back to the head of the linked list. While the stack is not empty, compare the value at the temp node to the value at the top of the stack. 
// Pop the stack and move the temp to the next node till it reaches the end.

bool isPalindrome1(Node* head) {
    stack<int> st;
    Node* temp = head;
    while(temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp)
    {
        if(temp->data != st.top()) return false;
        temp = temp->next;
        st.pop();
    }
    return true;
}

// Separate the LL into two halves and reverse the second half
// Then check for palindrome

Node* reverseLL(Node* head)
{
    if(head==NULL || head->next == NULL) return head;

    Node* newHead = reverseLL(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

bool isPalindrome2(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Now slow is at the middle
    Node* reverseLLHead = reverseLL(slow->next);

    Node* temp2 = reverseLLHead;
    Node* temp1 = head;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data!=temp2->data){
            slow->next = reverseLL(reverseLLHead); //Reverse the second half to its original state
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    slow->next = reverseLL(reverseLLHead); //Reverse the second half to its original state
    return true;
}

int main()
{
    vector<int> arr= {1,2,2,1};
    Node* head = createLinkedList(arr);
    if(isPalindrome1(head)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    if(isPalindrome2(head)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}



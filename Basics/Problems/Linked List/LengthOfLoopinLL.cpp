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

// First detect the loop and then find the length

int LengthOfTheLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    int length = 0;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) //Loop is detected
        {
            // Fix the slow
            // Only move the fast by one unit and do length++ till slow==fast
            while(fast)
            {
                fast=fast->next;
                length++;
                if(slow==fast) return length;                    
            }
        }
    }
    return 0;
}




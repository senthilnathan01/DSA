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

void deleteAtKthPlace(Node *head, int k) {
    if(head == NULL) return; //Empty List
    if(k==1)
    {
        Node* temp = head;
        head =  head -> next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;
    int count = 1;

    while(current && count<k)
    {
        prev = current;
        current = current -> next;

        count++;
    }

    if(current)
    {
        prev -> next = current -> next;
        delete current;
    }
}

int main()
{
    vector<int> arr = {1,2,3,4};
    Node* head = createLinkedList(arr);
    deleteAtKthPlace(head, 2);
    printLinkedList(head);
}

// OUTPUT:
// 1 3 4



#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* createDLL(vector<int>& arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
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

Node* DeleteKthNode(Node* head, int k)
{   
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    if(k==1)
    {
        // This is same as removing the head

        head = head->next;
        head->back = NULL;
        temp->next = NULL;
        delete temp;
        return head;
    }

    int count = 1;
    while(temp && count<k)
    {
        temp = temp->next;
        count++;
    }

    // Get the previous and succeeding nodes of temp
    Node* prev = temp->back;
    Node* front = temp->next;

    // Do linking between prev and front
    prev->next = front;
    if(front) front->back = prev;
    
    // Remove connections from temp
    temp->back = NULL;
    temp->next = NULL;

    // Delete temp
    delete temp;

    return head;
}

int main()
{
    vector<int> arr= {1,3, 5, 10};
    Node* head = createDLL(arr);
    printLinkedList(head);
    head = DeleteKthNode(head, 3);
    printLinkedList(head);
}

// OUTPUT:
// 1 3 5 10 
// 1 3 10
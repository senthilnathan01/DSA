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

Node* array2LL(vector<int>& arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i< arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4};
    cout<<array2LL(arr)->data;
}
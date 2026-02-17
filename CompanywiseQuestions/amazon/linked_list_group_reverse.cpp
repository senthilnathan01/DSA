/*
You are given the head of a Singly linked list. You have to reverse every k node in the linked list and return the head of the modified list.
Note: If the number of nodes is not a multiple of k then the left-out nodes at the end, should be considered as a group and must be reversed.

LINK: https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
*/

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // PLAN:
        // for every group
        // currhead will become tail that will point to next reversed group's head
        // currtail will become the head will be pointed to by the previous group
        // also we need to return the newHead (head of the first group), so update it only once in the whole process
        
        // Base Case
        if(!head || !head->next) return head;
        
        Node* curr = head;
        Node* newHead = nullptr;
        Node* tail = nullptr;
        
        // iteration
        while(curr){
            Node* groupHead = curr;
            Node* prev = nullptr;
            Node* nextNode = nullptr;
            int count = 0;
            
            // reverse the group
            while(curr && count<k){
                nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                count++;
            }
            
            // point prev group's tail to this new reversed group
            if(tail) tail->next = prev;
            
            // if the newHead unassigned, assign it -> this will be returned at the end
            if(!newHead) newHead = prev;
            
            // Move tail to the end of the reversed group
            // Remember groupHead was pointing to the first node before reversing
            // After reversing it will be at the last
            tail = groupHead;
        }
        return newHead;
    }
};

/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Leetcode Link: https://leetcode.com/problems/reverse-linked-list/description/
*/

// NOTE:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Solution 1:
// Using while loop
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Edge case
        if(head == NULL || head->next==NULL) return head;

        //Step 0: Setup the nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* front = head->next;

        // Step 1: (Linking)
        curr->next = NULL; // Tail points to NULL

        // Step 2: (Reassigning)
        prev = curr;
        curr = front;

        while(curr->next)
        {
            // Step 2 contd.
            front = curr->next;

            // Step 1
            curr->next = prev;

            // Step 2
            prev = curr;
            curr = front;
        }

        // Finally, one more step 1
        curr->next = prev;

        return curr;
    }
};

// Solution 2:
// Using recursion
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case
        if(head == NULL || head->next==NULL) return head;

        // Recursive Case
        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }
};

// Solution 3:
// Using stacks
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Base case
        if(head == NULL || head->next==NULL) return head;

        stack<int> st;
        ListNode* temp = head;
        while(temp)
        {
            st.push(temp->val);
            temp = temp->next;
        }

        // Use the same Linked List but just reverse the values
        temp = head;
        while(!st.empty())
        {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};

// Solution 4:
// Instead of changing the existing links
// Create a new linked list which is a reverse of the given one
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Edge case
        if(head == NULL || head->next==NULL) return head;

        // Let's create a new chain and submit that

        // Initialise a pointer in old chain
        // This guy is gonna give us the value
        ListNode* temp = head->next;

        // Initialise pointers for the new chain
        ListNode *curr = new ListNode(head->val, nullptr), *addition;

        while(temp)
        {
            addition = new ListNode(temp->val, curr);
            curr = addition;
            temp = temp->next;
        }
        return addition;
    }
};

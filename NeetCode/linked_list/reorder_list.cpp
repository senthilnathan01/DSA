/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Leetcode Link: https://leetcode.com/problems/reorder-list/description/
*/

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
    void reorderList(ListNode* head) {
        if(head==nullptr) return;

        vector<ListNode*> vec;
        ListNode* temp = head;
        while(temp)
        {
            vec.push_back(temp);
            temp=temp->next;
        }

        // Using two pointers
        int l = 0, r = vec.size() - 1;
        while(l < r)
        {
            vec[l]->next = vec[r];
            l++;
            if(l>=r) break;
            vec[r]->next = vec[l];
            r--;
        }

        vec[l]->next = nullptr;
    }
};

// Solution 2: 
// Using Fast and Slow Pointer -> Find the mid point and separate the lists into two halves
// Reverse the second half
// Merge the two halves
class Solution {
public:
    void reorderList(ListNode* head) {
        // No need to reorder if list has < 3 nodes
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Find the middle of the list using slow and fast pointers
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list starting from slow->next
        ListNode *second = slow->next; // First node of second half
        ListNode *prev = nullptr; // Will be the new head of the second half
        
        slow->next = nullptr; // Break the list into two halves

        while(second != nullptr)
        {
            ListNode* temp = second->next; // Save next node
            second->next = prev; // Reverse current node's pointer

            prev = second; // Move prev one step forward
            second = temp; // Move to next node
        }

        // Step 3: Merge the two halves - first half from head, second half from prev
        ListNode* first = head;  // Pointer for the first half
        second = prev;           // Pointer for the reversed second half

        while(second)
        {
            ListNode* tmp1 = first->next; // Save next node of first 
            ListNode* tmp2 = second->next; // Save next node of second 

            // Link first -> second and second->(first->next)
            first->next = second;
            second->next = tmp1;

            // Move pointers forward
            first = tmp1;
            second = tmp2;
        }
    }
};


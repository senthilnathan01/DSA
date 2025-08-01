/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Approach:
        // The best approach is to use Two Pointers:
        // Move one pointer n steps ahead, then move both until the first hits the end.

        // Create a dummy node to simplify edge cases (like deleting the head)
        ListNode* dummy = new ListNode(0, head);

        // Two Pointers
        ListNode *fast = dummy, *slow = dummy;

        // Step 1: Move fast pointer n steps ahead 
        for(int i = 0; i <= n; i++) fast = fast->next;

        // Step 2: Move both of the until fast reaches the end
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 3: Skip the node after slow
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;

        delete nodeToDelete;

        return dummy->next;

    }
};



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // reverse the list 
        // remove nth node from the end
        // reverse the list again
        
        // Step 1: reverse the list
        ListNode* newHead = reverseList(head);

        // Step 2: Delete the nth node from front
        int node = 1;
        ListNode* prev = nullptr;
        ListNode* curr = newHead;
        ListNode* front = newHead->next;

        while(node<n)
        {
            prev = curr;
            curr = front;
            front = front->next;
            node++;
        }

        // Found the node at curr
        if(prev)
        {
            prev->next = front;
            delete curr;
        }
        else
        {
            // We are deleting the head node
            ListNode* temp = newHead;
            newHead = newHead->next;
            delete temp;
        }

        return reverseList(newHead);

    }

    ListNode* reverseList(ListNode* head)
    {
        // Base Case
        if(!head || !head->next) return head;

        // Recursive Case
        ListNode* newHead = reverseList(head->next);
        head->next->next = head; // Link back
        head->next = nullptr; // Break forward link

        return newHead;
    }
};

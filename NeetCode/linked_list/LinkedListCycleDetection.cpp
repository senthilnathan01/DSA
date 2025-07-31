/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

Leetcode Link: https://leetcode.com/problems/linked-list-cycle/description/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Use two pointers 
        // Let the speed of one of the pointer be 1
        // Let the speed of the other be 2
        // If there is a cycle they will meet
        // If they terminate to null -> no cycle
        // Checking one of them is enough,
        // In this case let's check ptr2 as it moves fast

        ListNode *ptr1 = head, *ptr2= head;
        while(ptr2)
        {
            ptr1 = ptr1->next;
            if(ptr2->next) ptr2 = ptr2->next->next;
            else return false;

            if(ptr1==ptr2) return true;
        }

        return false;

    }
};

// Other approach is to use a hash set

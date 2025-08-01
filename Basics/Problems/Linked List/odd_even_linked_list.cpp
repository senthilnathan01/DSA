/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Leetcode Link: https://leetcode.com/problems/odd-even-linked-list/description/
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next == NULL  || head->next->next==NULL) return head;

        ListNode* oddHead = head;
        ListNode* evenHead = head->next;

        ListNode* oddTemp = head;
        ListNode* evenTemp = head->next;

        while(evenTemp && evenTemp->next)
        {
            oddTemp->next = evenTemp->next;
            oddTemp = oddTemp->next;
            evenTemp->next = oddTemp->next;
            evenTemp = evenTemp->next;
        }

        oddTemp->next = evenHead;
        return oddHead;
    }
};

/*
I KNOW THIS IS SIMPLE, BUT KNOWING THIS CAN HELP YOU SOLVE SOME OTHER COMPLEX PROBLEMS BUILDING ON THIS
OTHER PROBLEMS ARE ALSO IN OUR REPO
CHECK IT OUT!

Given the head of a singly linked list, reverse the list, and return the reversed list.

LINK: https://leetcode.com/problems/reverse-linked-list/description/
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
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        prev->next = nullptr;
        ListNode* temp;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

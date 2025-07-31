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

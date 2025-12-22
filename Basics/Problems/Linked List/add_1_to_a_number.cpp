/*
Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.



The number will contain no leading zeroes except when the value represented is zero itself.


Example 1

Input: head -> 1 -> 2 -> 3

Output: head -> 1 -> 2 -> 4

Explanation: The number represented by the linked list = 123.

123 + 1 = 124.

Example 2

Input: head -> 9 -> 9

Output: head -> 1 -> 0 -> 0

Explanation: The number represented by the linked list = 99.

99 + 1 = 100.
*/

/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode *reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode *nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode *addOne(ListNode *head) {
        head = reverse(head);
        ListNode* curr = head;
        int carry = 1;
        while(curr && carry){
            int sum = curr->val + carry;
            curr->val = sum%10;
            carry = sum/10;

            if(!curr->next && carry){
                curr->next = new ListNode(carry);
                carry = 0;
            }
            curr = curr->next;
        }

        return reverse(head);
    }
};

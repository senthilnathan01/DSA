/*
Given the head of a singly linked list consisting of only 0, 1 or 2.



Sort the given linked list and return the head of the modified list.



Do it in-place by changing the links between the nodes without creating new nodes.


Example 1

Input: linkedList = [1, 0, 2, 0 , 1]

Output: [0, 0, 1, 1, 2]

Explanation: The values after sorting are [0, 0, 1, 1, 2].

Example 2

Input: linkedList = [1, 1, 1, 0]

Output: [0, 1, 1, 1]

Explanation: The values after sorting are [0, 1, 1, 1].
*/

/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            ListNode dummy0(-1), dummy1(-1), dummy2(-1);
            ListNode *tail0 = &dummy0, *tail1 = &dummy1, *tail2 = &dummy2;

            ListNode* curr = head;

            while(curr){
                if(curr->data==0){
                    tail0->next = curr;
                    tail0 = curr;
                }
                else if(curr->data == 1){
                    tail1->next = curr;
                    tail1 = curr;
                }
                else{
                    tail2->next = curr;
                    tail2 = curr;
                }
                curr= curr->next;
            }

            tail2->next = nullptr;
            tail1->next = dummy2.next;
            tail0->next = dummy1.next;

            return dummy0.next;
        }
};

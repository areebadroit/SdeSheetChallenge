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
        ListNode *newHead = nullptr;
        ListNode *nextNode = head;
        while(nextNode != nullptr){
            nextNode = nextNode -> next;
            head -> next = newHead;
            newHead = head;
            head = nextNode;
        }
        return newHead;
    }
};
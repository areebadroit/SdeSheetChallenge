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
    ListNode* reverseLinkedList(ListNode* head){
        ListNode *newHead = nullptr;
        ListNode *temp = head;
        while(temp!=nullptr){
            temp=temp->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next = reverseLinkedList(slow->next);
        slow = slow->next;
        ListNode* p1 = head;
        while(slow!=nullptr){
            if(slow->val!=p1->val){
                return false;
            }
            slow=slow->next;
            p1=p1->next;
        }
        return true;
    }
};
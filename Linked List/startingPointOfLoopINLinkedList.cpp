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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                break;
            }
        }
        if(fast==nullptr || fast->next==nullptr){
            return nullptr;
        }
        ListNode* entry = head;
        while(entry!=slow){
            slow=slow->next;
            entry=entry->next;
        }
        return slow;
    }
};
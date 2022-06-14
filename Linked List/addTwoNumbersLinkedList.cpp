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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int sum = 0;
        int carry = 0;
        while(carry != 0 || l1 != nullptr || l2 != nullptr){
            if(l1!=nullptr){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* newNode = new ListNode(sum,nullptr);
            temp->next=newNode;
            temp = temp -> next;
            sum = 0;
        }
        return dummy->next;
    }
};
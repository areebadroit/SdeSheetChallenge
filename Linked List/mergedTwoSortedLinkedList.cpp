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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedList = nullptr;
        ListNode* temp = mergedList;
        while(list1 != nullptr && list2 != nullptr){
            ListNode* node = nullptr;
            if(list1->val < list2->val){
                node = list1;
                list1=list1->next;
            }else{
                node = list2;
                list2=list2->next;
            }
            if(mergedList == nullptr){
                mergedList = node;
                temp = node;
                node->next=nullptr;
            }else{
                temp->next=node;
                temp=temp->next;
                node->next=nullptr;
            }
        }
        while(list1 != nullptr){
            ListNode* node = nullptr;
            node=list1;
            list1=list1->next;
            if(mergedList == nullptr){
                mergedList = node;
                temp = node;
                node->next=nullptr;
            }else{
                temp->next=node;
                temp=temp->next;
                node->next=nullptr;
            }
        }
        while(list2 != nullptr){
            ListNode* node = nullptr;
            node=list2;
            list2=list2->next;
            if(mergedList == nullptr){
                mergedList = node;
                temp = node;
                node->next=nullptr;
            }else{
                temp->next=node;
                temp=temp->next;
                node->next=nullptr;
            }
        }
        return mergedList;
    }
};
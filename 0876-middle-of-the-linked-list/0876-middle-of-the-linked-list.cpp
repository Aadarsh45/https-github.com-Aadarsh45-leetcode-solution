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
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL){
            return head;
        }
        if(head->next->next==NULL){
            return head->next;
        }
        struct ListNode *fast=head;
        int cnt=1;
        while(fast->next!=NULL){
           cnt++;
           fast=fast->next;
        }
        cnt=cnt/2;
        while(cnt--){
            head=head->next;
        }
        return head;

        
    }
};
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head ==nullptr || head->next == nullptr || k==0)return head;
        int size = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        if(k%size == 0){
            return head;
        }
        size = size - k%size;
        ListNode* st = head;
        ListNode* prev = st;
       
        while(size--){
            prev = st; 
            st = st->next;

        }
        prev->next = nullptr;
        ListNode* res = st;
        while(st!=nullptr){
            if(st->next == nullptr){
                st->next = head;
                break;
            }
            st = st->next;
        }
        
        return res;
        
    }
};
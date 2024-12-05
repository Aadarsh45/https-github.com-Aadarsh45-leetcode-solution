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
        if(head->next == nullptr){
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        int cnt = 0;

        while(fast!=nullptr && fast->next != nullptr && fast->next->next != nullptr){
            
            fast = fast->next->next;
            slow = slow->next;
            if(fast->next == nullptr)return slow;

        }
        

        return slow->next;
        
    }
};
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* fast = head;
        ListNode* slow = dummy;

        while(fast){
            if( n > 0 )  fast= fast->next;
            else{
                slow = slow->next;
                fast = fast->next;
            }
            n--;
        }
        slow->next = slow->next->next;

        return dummy->next;
    }
};
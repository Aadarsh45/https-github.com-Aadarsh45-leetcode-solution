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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* curr = new ListNode(-1);
        ListNode* ans = curr;
        int cnt = 0;
        while(head != nullptr ){
            if(head->val == 0 && cnt != 0){
               // cout<<"*";
               ListNode *p = new ListNode(cnt);
               curr->next = p;
               curr = curr->next;
               cnt=0;
            }
            else{
                cnt+=head->val;
            }
            if(head->next == NULL) break;
            
            head = head->next;
            // cout<<cnt<<" "<<head->val<<" "<<curr->val<<endl;
        }
        
        return ans->next;
    }
};
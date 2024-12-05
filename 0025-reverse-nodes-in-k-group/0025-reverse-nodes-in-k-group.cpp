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
    ListNode* reverse(ListNode* head,int size,int k){
        if(size < k) return head;

        ListNode* res = new ListNode(-1,nullptr);
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nxt = head->next;

        while(nxt !=nullptr ){
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = prev;

        res->next = curr;

        return res->next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       
        ListNode* curr = head;
        ListNode* res = new ListNode(-1);
         ListNode* ans = res;
       
        while(curr!= nullptr){
            ListNode* temp = new ListNode();
            ListNode* t4 = temp;
            int cnt = 0;
            while(curr!= nullptr && cnt < k){
                ListNode* t2 = new ListNode(curr->val);
                temp->next = t2;
                temp = temp->next;
                cnt++;
                curr = curr->next;
            }
            ListNode* t3 = reverse(t4->next,cnt,k);
            res->next = t3;
            while(res->next!=nullptr){
                cout<<res->val<<endl;
                res = res->next;
            }

            

        }


        return ans->next;
        
    }
};
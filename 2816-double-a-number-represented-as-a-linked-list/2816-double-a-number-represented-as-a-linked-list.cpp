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
    
    ListNode* doubleIt(ListNode* head) {
        stack<int> stk;
        
        while(head != nullptr){
          
            stk.push(head->val);
            head= head->next;
        }
//         while(!stk.empty()){
           
//             cout<<stk.top()<<" " ;
//             stk.pop();
//         }
        
        stack<int>stk2;
        int carry = 0;
        
        while(!stk.empty()){
            int temp =2* stk.top();
            stk.pop();
            int number = temp%10;
            
            stk2.push(number+carry);
            carry = temp/10;
            
        }
        if(carry!= 0){
          stk2.push(carry);
        }
        
        
        ListNode *p = new ListNode(-1,NULL);
        ListNode* q = p;
        while(!stk2.empty()){
            
           ListNode *r = new ListNode(stk2.top(),NULL);
           p->next = r;
           p = r;
            
            stk2.pop();
        }
     
        
        return q->next;
        
    }
};
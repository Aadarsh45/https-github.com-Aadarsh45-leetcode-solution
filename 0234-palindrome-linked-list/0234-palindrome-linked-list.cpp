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
    bool isPalindrome(ListNode* head) {
    stack<int>stack;
    struct ListNode *temp=head;
    while(temp!=0){
        stack.push(temp->val);
        temp=temp->next;
    }
    while(!stack.empty()){
        if(head->val !=stack.top()){
            return false;
        }
        head=head->next;
        stack.pop();

    }
    return true;


        
    }
};
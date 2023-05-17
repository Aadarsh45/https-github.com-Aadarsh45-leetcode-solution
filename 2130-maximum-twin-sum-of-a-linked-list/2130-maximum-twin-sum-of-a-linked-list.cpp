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
    int pairSum(ListNode* head) {
        vector<int> arr;
        
        while(head!=NULL){
            arr.push_back(head->val);
            head=head->next;
        }
        
        int maxi = INT_MIN;
        int lo = 0;
        int hgh = arr.size()-1;
        while( lo < hgh){
            maxi = max(maxi,arr[lo]+arr[hgh]);
            lo++;
            hgh--;
        }
        return maxi;
    }
};
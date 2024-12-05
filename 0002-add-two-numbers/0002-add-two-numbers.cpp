class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(-1, nullptr);
        ListNode* curr = res;
        int carry = 0;

        // Process both lists
        while (l1 != nullptr && l2 != nullptr) {
            int sum = carry + l1->val + l2->val;
            carry = sum / 10;
            sum = sum % 10;
            curr->next = new ListNode(sum);
            curr = curr->next;  // Advance the curr pointer
            l1 = l1->next;  // Advance l1
            l2 = l2->next;  // Advance l2
        }

        // Process remaining nodes in l1
        while (l1 != nullptr) {
            int sum = carry + l1->val;
            carry = sum / 10;
            sum = sum % 10;
            curr->next = new ListNode(sum);
            curr = curr->next;  // Advance the curr pointer
            l1 = l1->next;  // Advance l1
        }

        // Process remaining nodes in l2
        while (l2 != nullptr) {
            int sum = carry + l2->val;
            carry = sum / 10;
            sum = sum % 10;
            curr->next = new ListNode(sum);
            curr = curr->next;  // Advance the curr pointer
            l2 = l2->next;  // Advance l2
        }

        // If there's any carry left
        if (carry != 0) {
            curr->next = new ListNode(carry);
        }

        return res->next;
    }
};

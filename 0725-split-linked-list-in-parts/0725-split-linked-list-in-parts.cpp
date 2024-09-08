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
vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res(k, nullptr);
        int n = 0;
        ListNode* temp = head;

        // Count the number of nodes in the list
        while (temp) {
            n++;
            temp = temp->next;
        }

        int partSize = n / k;
        int extraNodes = n % k;

        ListNode* current = head;
        ListNode* prev = nullptr;

        for (int i = 0; i < k; ++i) {
            res[i] = current;
            int currentPartSize = partSize + (i < extraNodes ? 1 : 0);
            for (int j = 0; j < currentPartSize; ++j) {
                prev = current;
                current = current->next;
            }
            if (prev) {
                prev->next = nullptr;
            }
        }

        return res;
    }
};

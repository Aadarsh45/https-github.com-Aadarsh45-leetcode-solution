/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int maxWidth = 0;
        queue<TreeNode*> node_q;
        queue<unsigned long long> index_q;
        node_q.push(root);
        index_q.push(1);
        while (!node_q.empty()) {
            int size = node_q.size();
            unsigned long long leftIndex = index_q.front(), rightIndex = 0;
            for (int i = 0; i < size; ++i) {
                TreeNode* curr = node_q.front();
                unsigned long long index = index_q.front();
                node_q.pop();
                index_q.pop();
                rightIndex = index;
                if (curr->left) {
                    node_q.push(curr->left);
                    index_q.push(index * 2);
                }
                if (curr->right) {
                    node_q.push(curr->right);
                    index_q.push(index * 2 + 1);
                }
            }
            maxWidth = max(maxWidth, (int)(rightIndex - leftIndex + 1));
        }
        return maxWidth;
    }
};
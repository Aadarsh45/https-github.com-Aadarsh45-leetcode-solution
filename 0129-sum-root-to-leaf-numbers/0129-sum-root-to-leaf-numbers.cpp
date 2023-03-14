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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* node, int sum) {
        if (!node) {
            return 0;
        }
        sum = sum * 10 + node->val;
        if (!node->left && !node->right) {
            return sum;
        }
        int left_sum = dfs(node->left, sum);
        int right_sum = dfs(node->right, sum);
        return left_sum + right_sum;
    }
};
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

    // Travserse entire tree using inorder, and store each element inside the res.
    void inorder(TreeNode* root, vector<int>&res) {
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        for(int i=1; i<res.size(); ++i) {
            // Checking if res[i-1] >= res[i] then return false;
            // That means the input tree is not a valid BST;
            if(res[i-1]>=res[i]) return false;
        }
        return true;
       
    }
};
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
  
    int n = 0 ;
    int minDepth(TreeNode* root) {
        if( root==NULL) return 0 ;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if(l > 0 and r > 0)
            return 1+min(l,r);
        else
            return  1+max(l,r);

    }
};
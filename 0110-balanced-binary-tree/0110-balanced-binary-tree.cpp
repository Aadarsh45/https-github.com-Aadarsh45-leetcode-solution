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
   bool ans = true;
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
      int l=  maxdepth(root);
      return ans;
   
    
        
        
        
    }
    int maxdepth(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int lft=maxdepth(node->left);
        int rgt=maxdepth(node->right);
        if(abs(lft-rgt)>1){
            ans=false;
        }

        
        return 1+max(lft,rgt);
    }
};
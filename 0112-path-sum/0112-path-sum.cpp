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
      bool ans=false;
    int sum=0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
        return 0;  
        }
   help(root,targetSum,sum);
        return ans;
    
        
        
    }
 void help(TreeNode* root,int target,int sum){
     if(root == NULL){
         return ;
     }
       
      if(root!=NULL){
          sum+=root->val;
      }
       if((root->left == NULL && root->right ==NULL)&&  sum==target){
          ans=true;
       }
       help(root->left,target,sum);
        help(root->right,target,sum) ;  
      
       
       
       
   }
};
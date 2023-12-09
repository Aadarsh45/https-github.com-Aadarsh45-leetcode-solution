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
    queue<int> stack;
     vector<int>answer;
    vector<int> inorderTraversal(TreeNode* root) {
       
        help(root);
        return answer;
       
     }
     void help( TreeNode* root){
         if(root==NULL){
             return ;
         }
       
       
        help(root->left);
          cout<<root->val<<endl;
          stack.push(root->val);
        help(root->right);
       

         while(!stack.empty()){
             answer.push_back(stack.front());
             stack.pop();
         }



     }
   
};
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_size=preorder.size();
        int in_size=inorder.size();
        
        if(pre_size != in_size){
            return NULL;
        }
        map<int,int>hashmap;
        
        for(int i=0;i<in_size;i++){
            hashmap[inorder[i]]=i;
        }
        return help(preorder,0,pre_size-1,inorder,0,in_size-1,hashmap);
        
    }
    
    TreeNode* help(vector<int>&preorder,int pre_start,int pre_end,vector<int>& inorder,int in_start,int in_end,map<int,int>&hashmap){
        if(in_start>in_end || pre_start>pre_end){
            return NULL;
        }
        TreeNode *node =new TreeNode(preorder[pre_start]);
        
        int root = hashmap[preorder[pre_start]];
        int root_lft=root-in_start;
        
        node->left= help(preorder,pre_start+1,pre_start+root_lft,inorder,in_start,root-1,hashmap);
        node->right= help(preorder,pre_start+root_lft+1,pre_end,inorder,root+1,in_end,hashmap);
        
        return node;
    }
};
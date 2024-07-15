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
    TreeNode* createBinaryTree(vector<vector<int>>& nums) {
       unordered_map<int, TreeNode*> mp;
       unordered_set<int> hasParent;
        
        for(auto it: nums){
            int parent = it[0];
            int child = it[1];
            int left = it[2];
            
            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }
            if(mp.find(child)==mp.end()){
                mp[child] = new TreeNode(child);
                
            }
            hasParent.insert(child);
        }
        
        TreeNode* ans = NULL;
        
        // Identify root node
        for(auto it: nums) {
            int parent = it[0];
            if(hasParent.find(parent) == hasParent.end()) {
                ans = mp[parent];
               
            }
        }
        
         for(auto it: nums){
            int parent = it[0];
            int child = it[1];
            int left = it[2];
            
            if(left == 1){
               mp[parent]->left = mp[child];
            }
            else{
                mp[parent]->right = mp[child];
            }
            
        }
        
        return ans;
        
    }
};
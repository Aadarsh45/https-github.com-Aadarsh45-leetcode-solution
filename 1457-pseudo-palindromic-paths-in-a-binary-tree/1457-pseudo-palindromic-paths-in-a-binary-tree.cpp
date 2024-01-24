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
    int isrequired(vector<int> &map){
        int oddCount = 0;
        for(auto i : map){
            if(i%2==1){
                oddCount++;
            }
        }
        if(oddCount>1) return 0;
        return 1;
    }
    int recur(TreeNode* curr, vector<int> &map){
        if(!(curr->left) && !(curr->right)){
            map[curr->val]++;
            int ans = isrequired(map);
            map[curr->val]--;
            return ans;
        }
        map[curr->val]++;
        int ans = 0;
        if(curr->left){
            ans += recur(curr->left, map);
        }
        if(curr->right){
            ans += recur(curr->right, map);
        }
        map[curr->val]--;
        return ans;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> map(10,0);
        return recur(root,map);
    }
};
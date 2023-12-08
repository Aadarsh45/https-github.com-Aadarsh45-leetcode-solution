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
static const auto DPSolver = []()
{ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 'c'; }();
using namespace std;
class Solution {
public:
   
void tree2strVoid(TreeNode *root, string &res)
{
    if(!root)
        return ; 
    
    res += to_string(root->val);
    bool left = false;

    if (root->left){
        res+='(';
        tree2strVoid(root->left, res); 
        res+=')';
        left = true;

    }  
    if (root->right){
        if (!left){
        res+='(';
        res+=')';
        } 
        res+='(';
        tree2strVoid(root->right, res); 
        res+=')';
    }
}

string tree2str(TreeNode *root)
{
    DPSolver; 
    string res = ""; 
    tree2strVoid(root, res); 
    return res; 
}
};
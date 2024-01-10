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
    int ans = 0;
    void buildGraph(TreeNode* root,vector<vector<int>> &adj){
      if(root == nullptr){
        return;
      }
      if(root->left){
        adj[root->val].push_back(root->left->val);
        adj[root->left->val].push_back(root->val);
      }
       if(root->right){
        adj[root->val].push_back(root->right->val);
        adj[root->right->val].push_back(root->val);
      }
      buildGraph(root->left,adj);
      buildGraph(root->right,adj);

    }
  
  void bfs(vector<vector<int>>&adj,vector<int>&visited,int s){
    queue<int>q;
    visited[s] = 1;
    q.push(s);
 
    while (!q.empty()) {
 
        // Dequeue a vertex from queue and print it
        s = q.front();
        cout << s << " "<<ans<<endl;
        q.pop();
 
        // Get all adjacent vertices of the dequeued
        // vertex s.
        // If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjacent : adj[s]) {
            if (visited[adjacent] == 0) {
                visited[adjacent] = visited[s]+1;
                q.push(adjacent);
              cout<<adjacent<<" ";
            }
        }
      cout<<endl;
     ans = max(visited[s]+1,ans); 
    }
    
  }
    int amountOfTime(TreeNode* root, int start) {
      vector<vector<int>> adj(100001);
      vector<int>visited(100001,0);
     
      buildGraph(root,adj);
      
      bfs(adj,visited,start);
      
      return ans-2;
        
    }
};
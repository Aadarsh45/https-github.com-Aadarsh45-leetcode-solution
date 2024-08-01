class DisjointSet {
    vector<int> rank, parent,size;
public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
     void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        

        DisjointSet ds(n);
        sort(accounts.begin(),accounts.end());
        unordered_map<string,int>mp;          // email -> index

        for(int i = 0;i<n;i++){
            int m = accounts[i].size();
            for(int j = 1;j<m;j++){
                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }
                else{
                    int idx = mp[accounts[i][j]];
                    ds.unionBySize(idx,i);
                }
            }
        }

        vector<string> mailNode[n];
        for(auto it: mp){
            int idx = ds.findUPar(it.second);
            string email = it.first;
            mailNode[idx].push_back(email);
        }

        vector<vector<string>> ans;
        for(int i =0;i<n;i++){
            if(mailNode[i].size() == 0) continue;
            sort(mailNode[i].begin(),mailNode[i].end());

            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mailNode[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
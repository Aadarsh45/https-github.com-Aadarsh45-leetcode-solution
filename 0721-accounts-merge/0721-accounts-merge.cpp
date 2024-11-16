#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int U, int V) {
        int ulp_u = findUPar(U);
        int ulp_v = findUPar(V);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& details) {
        int n = details.size();
        DisjointSet ds(n);
        sort(details.begin(), details.end());
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                if (mp.find(details[i][j]) == mp.end()) {
                    mp[details[i][j]] = i;
                } else {
                    ds.unionBySize(i, mp[details[i][j]]);
                }
            }
        }

        vector<vector<string>> vec(n);
        for (auto it : mp) {
            string str = it.first;
            int a = ds.findUPar(it.second);
            vec[a].push_back(it.first);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (vec[i].empty()) continue;
            sort(vec[i].begin(), vec[i].end());
            vector<string> temp;
             temp.push_back(details[i][0]);
            for (auto it : vec[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

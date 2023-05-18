class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

         vector<int> arr, visited(n);

        for (auto& i: edges)
            visited[i[1]] = 1;

        
        for (int i = 0; i < n; ++i)
            if (visited[i] == 0)
                arr.push_back(i);
                
        return arr;
        
    }
};
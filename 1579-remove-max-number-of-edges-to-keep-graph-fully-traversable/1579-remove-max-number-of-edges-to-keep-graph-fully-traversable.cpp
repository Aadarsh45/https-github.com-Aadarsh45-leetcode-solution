class Solution {
public:
    int findParent(vector<int>&parent, int node)
    {
        if (parent[node] == node) return node;
        else return findParent(parent, parent[node]);
    }
    bool merge(vector<int>&parent, vector<int>&rank, int node1, int node2)
    {
        int parent1 = findParent(parent, node1);
        int parent2 = findParent(parent, node2);
        if (parent1 == parent2) return false;
        else
        {
            //NON-OPTIMAL WAY => { parent[parent1] = parent2 or parent[parent2] = parent2; return; :)} 
            //OPTIMAL WAY=> merge based on rank to reduce complexity in 'FINDING PARENT' next time
            if (rank[parent1] == rank[parent2])  //both at same level
            {
                parent[parent1] = parent2; 
                rank[parent2]++; 
            }
            else if (rank[parent1] < rank[parent2]) //parent2 is at higher level
                parent[parent1] = parent2; 
            else  //parent1 is at higher level
                parent[parent2] = parent1;
            return true;
        }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        int notUsed = 0, componentCount = n;
        vector<int>parent(n + 1);
        vector<int>rank(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
        //===========================================================================
        //COMMON FOR BOTH
        for (vector<int>&edge : edges)
        {
            if (edge[0] != 3) continue;
            
            bool merged = merge(parent, rank, edge[1], edge[2]);
            if (!merged) notUsed++;
            else componentCount--;
        }
        //===========================================================================
        //ONLY FOR ALICE
        vector<int>aliceParent = parent, aliceRank = rank;
        int aliceComponentCount = componentCount;
        for (vector<int>&edge : edges)
        {
            if (edge[0] != 1) continue;
            bool merged = merge(aliceParent, aliceRank, edge[1], edge[2]);
            if (!merged) notUsed++;
            else aliceComponentCount--;
        }
        if (aliceComponentCount != 1) return -1;  //still not connected, so return -1
        //==============================================================================
        //ONLY FOR BOB
        //could have used tha main 'parent', 'rank', 'componentCount'...
        //made duplicate copies here also only to explain 
        vector<int>bobParent = parent, bobRank = rank; 
        int bobComponentCount = componentCount;
        for (vector<int>&edge : edges)
        {
            if (edge[0] != 2) continue;
            bool merged = merge(bobParent, bobRank, edge[1], edge[2]);
            if (!merged) notUsed++;
            else bobComponentCount--;
        }
        if (bobComponentCount != 1) return -1;  //still not connected, so return -1
        //================================================================================
        return notUsed;//not used edges will be removed
        
    }
};
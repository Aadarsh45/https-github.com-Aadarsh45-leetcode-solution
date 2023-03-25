class Solution {
public:
    // parent vector
    vector<int> parent;

    // find function 
    int find(int n){
        if(n==parent[n]) return n;
        return parent[n] = find(parent[n]);
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        // initializing the vector, where the node will be parent of itself before we get known to the edges of the graph
        for(int i=0;i<n;i++) parent[i]=i;
        // the union find logic where we find parents of the two independent nodes and in case they are different we merge them so that we get to know further whether the node belongs to same parent or not
        for(auto &i:edges){
            int x = find(i[0]);
            int y = find(i[1]);
            if(x!=y) parent[y]=x;
        }
        unordered_map<int, int> mp;
        // frequency of parents of nodes gives us an idea of total graphs, and number of nodes within them
        for(auto &i:parent){
            mp[find(i)]++;
        }
        vector<long long> graphcount, suff;
        // storing the count in a vector
        for(auto &i:mp) graphcount.push_back(i.second);
        reverse(graphcount.begin(), graphcount.end());
        suff = graphcount;
        // if we have only one graph then no pairs will be formed
        if(graphcount.size()==1) return 0;
        // suffix array to keep count of total nodes after the current graph nodes
        for(int i=suff.size()-2;i>=0;i--) suff[i]+=suff[i+1];
        long long ans=0;
        // here no. of pairs will be : number of nodes in a graph * total number of nodes except that graph
        // to avoid repetition we are simply traversing so we get unique pairs
        for(int i=0;i<suff.size()-1;i++){
            ans+=(long long)(graphcount[i]*suff[i+1]);
        }
        return ans;
    }
};
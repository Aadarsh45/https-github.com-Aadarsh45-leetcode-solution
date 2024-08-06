class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<int, map<int,int>>mp;
        for(auto vec:pick)
           mp[vec[0]][vec[1]]++;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(auto [a, b]:mp[i])
            {
                if(b > i)
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};
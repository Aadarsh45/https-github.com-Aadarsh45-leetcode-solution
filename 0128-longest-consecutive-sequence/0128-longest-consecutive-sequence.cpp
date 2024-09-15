class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0) return 0;
        unordered_set<int>mp;
        int maxi = 1;

        for(auto it: nums){
            mp.insert(it);
        }
        for(auto it: mp){
           
            if(mp.find(it-1) == mp.end()){
                 int cnt = 1;
                 int x= it;
                 while(mp.find(x+1)!=mp.end()){
                    x++;
                    cnt++;
                 }
                 maxi = max(maxi,cnt);

            }
            
        }
        return maxi;
        
    }
};
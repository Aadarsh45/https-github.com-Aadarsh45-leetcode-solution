class Solution {
public:
    int mod  = 1e9+7;
    bool check(vector<int> &nums,int x,int k,int m){
        int cnt = 0;
        int t = 0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] <= x ){
                t++;
                if(t == k){
                    cnt++;
                    t = 0;
                }
            }
            else{
                t = 0;
            }
         }
        
        return cnt >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long cnt = m * 1ll * k * 1ll;
        int n = bloomDay.size();
        int maxi = 0;
        int mini = 1e9+7;
        
        for(int i = 0;i<n;i++){
            maxi = max(maxi,bloomDay[i]);
            mini = min(mini,bloomDay[i]);
        }
        // cout<<cnt<<" "<<maxi<<endl;
        if(cnt > n) return -1;
        
        int lo =mini;
        int hgh = maxi;
        int ans =  hgh;
        
        while(lo <= hgh){
            int mid = lo+(hgh-lo)/2;
         
            bool temp = check(bloomDay,mid, k,m);
             if(temp){
                 ans = mid;
                 hgh = mid-1;
             } 
            else{
                lo = mid+1;
            }
       }
       return ans;
    }
};
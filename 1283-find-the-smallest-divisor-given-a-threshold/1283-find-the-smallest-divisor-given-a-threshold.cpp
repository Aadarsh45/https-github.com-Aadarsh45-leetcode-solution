class Solution {
public:
    bool check(vector<int>& nums,int x,int k){
        int sum = 0;
        for(int i =0; i< nums.size();i++){
            int temp =(nums[i]/x);
            if(nums[i]%x != 0) temp++;
            
            sum+=temp;
            // cout<<temp<<" ";
            
        }
        // cout<<endl;
        if(sum <= k) return true;
        
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int lo = 1;
        int hgh = 0;
        for(int i =0;i<n;i++){
            hgh = max(hgh,nums[i]);
        }
        int ans = hgh;
        
        while( lo <= hgh){
            int mid = lo+(hgh-lo)/2;
            // cout<<mid;
            if(check(nums,mid,threshold)){
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
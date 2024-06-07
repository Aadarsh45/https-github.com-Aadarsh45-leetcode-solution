class Solution {
public:
    int fun(vector<int>&nums,int k,int mid){
        long long cnt = 0;
        int split = 1;
        
        for(int i =0;i<nums.size();i++){
            if(nums[i]+cnt <= mid){
                cnt+=nums[i];
            }
            else{
                cnt = nums[i];
                split++;
            }
        }
        
        if(split > k) return true;
        
        return false;
            
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = *max_element(nums.begin(),nums.end());
        int sum = 0; 
        for (int i = 0; i < n; i++)
        {sum += nums[i];}
        int hgh = sum;
        int ans = lo;
        
        while(lo <= hgh){
            int mid = lo+(hgh-lo)/2;
            
            if(fun(nums,k,mid)){
                lo = mid+1;
            }
            else{
                hgh = mid-1;
            }
        }
        
        return lo;
        
        
    }
};
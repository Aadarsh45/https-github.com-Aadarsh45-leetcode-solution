class Solution {
public:
    bool possible(vector<int>&nums,int mid,int k){
        long long int win_sum = 0,totalsum = 0;
        for(int i =0 ;i<mid;++i){
            win_sum+=nums[i];
        }
        totalsum=1LL*nums[mid-1]*mid;
        
        if(totalsum-win_sum <= k){
            return true;
        }
        int j =0;
        for(int i =mid;i<nums.size();++i){
            win_sum-=nums[j];
            win_sum+=nums[i];
            totalsum=totalsum=1LL*nums[i]*mid;
            if(totalsum-win_sum <= k){
              return true;
            }
            j++;
        }
        return false;
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int lo=1,hgh = nums.size(),ans=0;
        
        while(lo<=hgh){
            int mid = lo+(hgh-lo)/2;
            if(possible(nums,mid,k)){
                ans = mid;
                lo = mid+1;
            }
            else{
                hgh = mid-1;
            }
        }
        return ans;
    }
};
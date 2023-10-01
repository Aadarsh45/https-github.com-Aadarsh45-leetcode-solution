class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>left(n);
        vector<int>rgt(n);
        rgt[n-1]=nums[n-1];
        
        left[0]= nums[0];
        
        
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            rgt[i]=max(rgt[i+1],nums[i]);
        }
        long long maxi =0;
        for(int j = 1;j<n-1;j++){
            long long temp = (left[j-1]-nums[j]);
            temp*= rgt[j+1];
            
            maxi = max(maxi,temp);
        }
        if(maxi < 0) return 0;
        
        return maxi;
         
        
    }
};
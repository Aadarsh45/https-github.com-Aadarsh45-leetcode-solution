class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        for(int i = 0;i<n-3;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i+1;j<n-2;j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; 

                int lo = j+1,hgh = n-1;

                while(lo < hgh){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[lo] + (long long)nums[hgh];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[lo], nums[hgh]});
                        while (lo < hgh && nums[lo] == nums[lo + 1]) lo++; // Skip duplicates for the third number
                        while (lo < hgh && nums[hgh] == nums[hgh - 1]) hgh--; // Skip duplicates for the fourth number
                        lo++;
                        hgh--;
                    }
                    else if(sum < target) lo++;
                    else hgh--;
                    
                }
            
        }
     
        
    }
       return res;
    }
};
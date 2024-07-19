class Solution {
public:
    long long maximumPoints(vector<int>& nums, int currentEnergy) {
        int n = nums.size();
        if(n == 1 && currentEnergy > nums[0]) return currentEnergy/nums[0];
        sort(nums.begin(),nums.end());
        long long points = 0;
        long long ans = points;
        int j = n-1;
        if(currentEnergy < nums[0])return 0;
        
        while( j>0){
            if(currentEnergy >= nums[0]){
                points += 1ll*(currentEnergy/nums[0]);
                currentEnergy %=nums[0];
            }
            else {
               currentEnergy+=nums[j];
                j--;
            }
            // cout<<points<<" "<<currentEnergy<<endl;
            ans = max((points),(ans));
        }
        if(currentEnergy >= nums[0]){
                points += currentEnergy/nums[0];
                currentEnergy %=nums[0];
        }
        // cout<<points<<" "<<currentEnergy<<endl;
            ans = max((points),(ans));
        
        return ans;
        
    }
};
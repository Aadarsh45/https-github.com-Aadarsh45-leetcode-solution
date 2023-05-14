class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        if(nums.size() == 1 && nums[0].size()==1){
            return nums[0][0];
        }
        int n = nums[0].size();
        
        int ans = 0;
       for(int i=0;i<nums.size();i++){
            sort(nums[i].begin(),nums[i].end(),greater<int>());
        }
    //     for (int i = 0; i < nums[0].size(); i++) {
    //     for (int j = 0; j < nums.size(); j++)
    //         cout << nums[j][i] << " ";
    //     cout << endl;
    // }
        for(int i=0;i<nums[0].size();i++){
            int temp=0;
           for(int j=0;j<nums.size();j++){
               temp=max(temp,nums[j][i]);
           }
            ans=ans+temp;
        }
         
        return ans;
        
    }
};

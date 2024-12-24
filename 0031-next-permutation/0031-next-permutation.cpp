class Solution {
public:
    int findBreakPoint(vector<int>&arr,int n){
        int i = -1;
        for(int j = n-2;j>=0;j--){
            if(arr[j] < arr[j+1]){
                i = j;
                break;
            }
        }

        return i;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int breakPoint = findBreakPoint(nums,n);

        if(breakPoint == -1){
            return reverse(nums.begin(),nums.end());
        }
        for(int i = n-1;i > breakPoint;i--){
            if(nums[i] > nums[breakPoint]){
                swap(nums[i],nums[breakPoint]);
                break;
            }

        }
        reverse(nums.begin()+breakPoint+1,nums.end());
        
    }
};
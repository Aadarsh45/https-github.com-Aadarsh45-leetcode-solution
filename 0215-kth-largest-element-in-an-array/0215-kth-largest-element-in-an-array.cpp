class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pg;
        for(int i=0;i<nums.size();i++){
            pg.push(nums[i]);
        }
        k--;
        while(k--){
            cout<<pg.top();
            pg.pop();
        }
        return pg.top();
    }
};
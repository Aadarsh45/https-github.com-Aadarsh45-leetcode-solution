class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1 = 0;
        int maj2 = 0;
        int cnt1 = 0,cnt2 = 0;

        for(auto it: nums){
            if(it == maj1){
                cnt1++;
            }
            else if(it == maj2){
                cnt2++;
            }
            else if(cnt1 == 0){
                maj1 = it;
                cnt1++;
            }
            else if(cnt2 == 0){
                maj2 = it;
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;cnt2 = 0;
        for(auto it:nums){
            if(it == maj1){
                cnt1++;
            }
            else if(it == maj2){
                cnt2++;
            }
        }
        vector<int>res;

        if(cnt1> nums.size()/3){
            res.push_back(maj1);
        }
        if(cnt2> nums.size()/3){
            res.push_back(maj2);
        }

        return res;

        
    }
};
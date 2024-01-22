class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int n=nums.size();
        vector<bool> seen(n+1, 0);
        int dup, xorSum=0;
        for(int i=0; i<n; i++){
            int x=nums[i];
            if (seen[x]==1) dup=x;
            else seen[x]=1;
            xorSum^=(x^(i+1));//the final xorSum is mssing^dup
        }
        int missing=xorSum^dup;
        return {dup, missing}; 
    }
};
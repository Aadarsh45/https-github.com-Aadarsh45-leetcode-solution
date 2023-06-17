class Solution {
private:

int check(int idx, int prev, vector<int>& arr1 ,vector<int>& arr2, 
        vector<unordered_map<int,int> >& dp){

        if(idx == arr1.size())  return 0;
        if(dp[idx].find(prev) != dp[idx].end())    return dp[idx][prev];

        int notTake,take;
        if(arr1[idx] > prev)    
            notTake = check(idx+1, arr1[idx], arr1, arr2, dp);
        else
            notTake = INT_MAX;

        int rep = upper_bound(arr2.begin(),arr2.end(), prev) - arr2.begin();
        if(rep == arr2.size())
            take = INT_MAX;
        else{
            int temp = check(idx+1,arr2[rep],arr1,arr2,dp);
            if(temp == INT_MAX)  take = INT_MAX;
            else take = 1 + temp;
        }

    return dp[idx][prev] = min(take,notTake);
}

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        vector<unordered_map<int,int>> dp(2001);  
        int val = check(0, INT_MIN, arr1, arr2, dp);
        if(val == INT_MAX)
            return -1;
        return val;
    }
}; 
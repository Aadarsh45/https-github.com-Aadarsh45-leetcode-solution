class Solution {
public:
    bool compare(string& s1, string& s2){
    if(s1.size() != s2.size() + 1) return false;
    
    int first = 0;
    int second = 0;
    
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first ++;
            second ++;
        }
        else first ++;
    }
    if(first == s1.size() && second == s2.size()) return true;
    else return false; 
}

bool comp(string& s1, string& s2){
    return s1.size() < s2.size();
}
    int longestStrChain(vector<string>& nums) {
        
        int n = nums.size();
        std::sort(nums.begin(), nums.end(), [](const std::string &a, const std::string &b) {
        return a.length() < b.length();
    });

        
        int ans = 1;
        
        vector<int> dp(n,1);
        
        for(int i =0;i<n;i++){
            cout<<nums[i]<<endl;
            for(int j =0;j<i;j++){
                if(compare(nums[i],nums[j]) && 1+dp[j] > dp[i]){
                    dp[i] = dp[j]+1;
                }
            }
            if(dp[i] > ans){
                ans = dp[i];
            }
        }
        
        return ans;
        
    }
};
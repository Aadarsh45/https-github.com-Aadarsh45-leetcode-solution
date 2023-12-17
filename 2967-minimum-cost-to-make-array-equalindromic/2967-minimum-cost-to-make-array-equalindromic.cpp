class Solution {
public:
    long long cost(vector<int>nums,int x){    //calculating the cost;
        long long ans;
        for(auto it:nums){
            ans+=abs(it-x);
        }
        cout<<ans;
        return ans;
    }
    
    
    bool check(int a){   //check the palindrome
        int rev = 0, orig = a;
        while (a > 0) {
            rev = rev * 10 + a % 10;
            a/= 10;
        }
        return rev == orig;
    }
    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int med = nums[n/2];
        cout<<med;
        
        long long lft = isPalindrome1(nums,med);
        long long rgt = isPalindrome2(nums,med);
        cout<<lft<<rgt<<endl;
        
        return  min(lft,rgt);
        
    }
    long long isPalindrome1(vector<int>nums,int med){
        while(!check(med)){
            med--;
        }
        return cost(nums,med);
        
    }
    long long isPalindrome2(vector<int>nums,int med){
        while(!check(med)){
            med++;
        }
        return cost(nums,med);
    }
};
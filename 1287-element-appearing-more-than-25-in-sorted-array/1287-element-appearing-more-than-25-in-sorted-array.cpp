class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count=0;
        int maxi_count=0;
        int ans=0;
        int n=arr.size();
        if(n<2) return arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                count++;
            }
            else count=0;

            if(count>maxi_count){
              maxi_count=count;
            ans=arr[i];  
            }
            
        }
        
        return ans;
    }
};
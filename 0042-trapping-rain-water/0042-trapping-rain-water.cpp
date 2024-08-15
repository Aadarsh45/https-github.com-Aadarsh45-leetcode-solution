class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pre(n,0);
        vector<int>suff(n,0);
        pre[0] = height[0];
        suff[n-1] = height[n-1];

        for(int i = 1;i<n;i++){
            pre[i] = max(pre[i-1],height[i]);
        }
        for(int i = n-2;i>=0;i--){
            suff[i] = max(suff[i+1],height[i]);
        }
        
       int water = 0;
       
       for(int i = 0;i<n;i++){
        int mini = min(pre[i],suff[i]);
        water += mini - height[i];
       }
       return water;
    
       
        
    }
};
class Solution {
public:
    vector<vector<int>> dp;
    unordered_map<int,int> mp;
    bool f(int i,vector<int>& stones,int k){
         if(i==stones.size()-1){
             return true;
         }
         if(i>=stones.size())return false;
         if(dp[i][k]!=-1)return dp[i][k];
         bool p1=false;
         bool p2=false;
         bool p3=false;
        //  cout<<i<<endl;
         if(i==0){
           if(mp.find(i+1)!=mp.end()){
               int in=mp[i+1];
               p1=f(in,stones,1);
           }
         }else{
             
             int i1=stones[i]+k+1;
             int i2=stones[i]+k;
             int i3=stones[i]+k-1;
             int in;
             if(mp.find(i1)!=mp.end() && mp[i1]>i){
                   in=mp[i1];
                  p1=f(in,stones,k+1);
             }
             if(p1)return dp[i][k]=p1;
             if(mp.find(i2)!=mp.end() && mp[i2]>i){
                   
                   in=mp[i2];
                  p2=f(in,stones,k);
             }
             if(p2)return dp[i][k]=p2;
             if(mp.find(i3)!=mp.end() && mp[i3]>i){
                   in=mp[i3];
                  p3=f(in,stones,k-1);
             }
             if(p3)return dp[i][k]=p3;
         }
         return dp[i][k]=p1 || p2 || p3;

     }
    
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        dp.resize(n+1,vector<int>(n+1,-1));
        return f(0,stones,1);
    }
};
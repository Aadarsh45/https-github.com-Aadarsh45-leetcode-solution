class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      
      int n = intervals.size();
      if(n == 1){
        return intervals;
      }
      
      sort(intervals.begin(),intervals.end());
      vector<vector<int>>ans;
     
      for(int i = 0;i<n;i++){
        int first = intervals[i][0];
        int col = intervals[i][1];
        int j = i+1;
        while(j<n && intervals[j][0]<=col){
          col = max(intervals[j][1],col);
          j++;
        }
        ans.push_back({first,col});
        i= j-1;
        
      }
      
      return ans;
        
    }
};
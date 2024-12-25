class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int n = intervals.size();

        for(int i = 0;i<n;i++){
            if(res.size() == 0){
                res.push_back(intervals[i]);
                continue;
            }
            int comp = res.back()[1];
            if(intervals[i][0] <= comp){
                res.back()[1] = max(comp,intervals[i][1] );
            }
            else{
                res.push_back(intervals[i]);

            }

        }
        return res;
        
    }
};
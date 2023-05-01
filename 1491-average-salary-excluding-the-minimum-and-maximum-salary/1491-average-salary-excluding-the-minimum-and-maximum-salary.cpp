class Solution {
public:
    double average(vector<int>& salary) {
        double ans;
        int cnt;
        double temp;
        
        sort(salary.begin(),salary.end());
        
        for(int i = 1; i<salary.size()-1; i++){
            ans+=salary[i];
            cnt++;
        }
        
        return (ans/cnt);
        
    }
};
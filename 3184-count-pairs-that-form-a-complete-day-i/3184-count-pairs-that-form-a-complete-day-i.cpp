class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        for(int i = 0; i< n ;i++){
            hours[i]%=24;
        }
        int cnt = 0;
        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                int t = hours[i]+hours[j];
                if(t%24 == 0) cnt++;
            }
        }
        return cnt;
        
    }
};
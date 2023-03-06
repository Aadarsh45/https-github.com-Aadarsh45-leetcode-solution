class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int cnt = 0;
        int i=0;
        while(cnt <= k && i<n){
            if(cnt == k){
                break;
            }
            if(i+1+cnt != arr[i] ){
                cnt++;
            }
           else  if(i+1+cnt == arr[i] ){
                i++;
            }
            
         }
       
       
        while(cnt < k ){
            cnt++;
        }
        return i+cnt;
    }
};
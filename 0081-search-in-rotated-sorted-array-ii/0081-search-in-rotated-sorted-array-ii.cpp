class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int n = arr.size();
        int lo = 0;
        int hgh = n-1;
        
        while(lo <= hgh){
            int mid = lo+(hgh-lo)/2;
            if(arr[mid] == target) return true;
            
            if(arr[lo] == arr[mid] && arr[mid] == arr[hgh]) {
                lo++;
                hgh--;
                continue;
            }
             
             if(arr[lo] <= arr[mid]){
                 if(arr[lo] <= target && target <= arr[mid]){
                hgh = mid-1;
                
            }
             else{
                 lo = mid+1;
             }
             }
            
             else{
                 if(arr[mid] <= target && target <= arr[hgh]){
                     lo = mid+1;
                 }
                 else{
                     hgh = mid-1;
                 }
                 
             }
         }
        return false;
   }
};
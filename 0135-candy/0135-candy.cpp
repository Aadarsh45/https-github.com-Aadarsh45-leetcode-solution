class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum = 1;
        int i = 1;
        
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                sum+=1;
                continue;
             }
            int peak = 1;
            while(i<n && ratings[i] > ratings[i-1]){
                peak+=1;
                i++;
                sum+=peak;
            } 
            int down =1;
            while(i<n && ratings[i] < ratings[i-1]){
                sum+=down;
                i++;
                down+=1;
            }
            
            if(down > peak) sum+=(down-peak);
        }
        return sum;
    }
};
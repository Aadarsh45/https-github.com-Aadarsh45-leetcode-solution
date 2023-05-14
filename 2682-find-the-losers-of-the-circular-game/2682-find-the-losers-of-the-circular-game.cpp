class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int>ans;
        unordered_set<int>set;
        set.insert(1);
        int temp;
        int curr= 1;
        for(int i = 1; i<n+1;i++){
             
            temp =curr+ i*k;
            
            temp=temp%n;
            if(temp == 0){
                temp = n;
            }
            curr = temp;
            if(set.find(curr) != set.end()){
                break;
             }
            set.insert(curr);
          
        }
        for(int i = 1;i<n+1;i++){
             if(set.find(i) == set.end()){
                ans.push_back(i);
             }
            
        }
        return ans;
    }
};
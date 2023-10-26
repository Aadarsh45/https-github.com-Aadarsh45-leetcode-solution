class Solution {
public:
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int ,long long int>m;
        sort(arr.begin(),arr.end());
        
        for(int x = 0;x<arr.size();x++){
            m.insert({arr[x],1});
        }
        
        for(int i =0;i<arr.size();i++){
            auto it = m.find(arr[i]);
            long long int cnt = 0;
            for(int j =0;j<i;j++){
                if(arr[i]%arr[j] == 0){
                    auto it2 = m.find(arr[i]/arr[j]);
                    auto it3 = m.find(arr[j]);
                    if(it2 != m.end()){
                        cnt+=(it2->second)*(it3->second); 
                        
                    }
                 } 
            }
            it->second+=cnt;
            
           
        }
        long long int sum = 0;
        for(auto it4 = m.begin();it4!=m.end();it4++){
            sum+=it4->second;
        }
        
        return sum%(1000000007);
    }
};
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int  n = nums.size();
        vector<int>ans;
         multimap<int,int>hash;
        
        for(int i = 0;i<n;i++){
           string temp = to_string(nums[i]);
           int j = 0;
            string t2 = "";
            while(j < temp.length()){
                int a = mapping[int(temp[j]-48)];
                char t4 = char(a);
                t2+= to_string(t4);
                j++;
            }
            cout<<t2<<endl;
            int t3 = stoi(t2);
            hash.insert({t3,nums[i]});
           
            
        }
        for(auto it : hash){
            ans.push_back(it.second);
        }
        
        return ans;
        
    }
};
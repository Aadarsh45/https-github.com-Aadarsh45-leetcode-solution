class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        int n = str.size();
        if(n == 0)return  {{}};
        unordered_map<string,vector<string>> m;

       
        for(int i = 0;i<n;i++){
            string key = get_key(str[i]);
            m[key].push_back(str[i]);

        }
         vector<vector<string>> ans;

         for(auto it: m){
            ans.push_back(it.second);
         }
         return ans;
        
    }
    private:
    string get_key(string temp){
        vector<int>cnt(26,0);
        for(int j = 0;j<temp.size();j++){
            cnt[temp[j] - 'a']++;
        }

        string key = "";
        for(int i = 0;i<cnt.size();i++){
            key.append(to_string(cnt[i]+'#'));
        }
        return key;
    }
};
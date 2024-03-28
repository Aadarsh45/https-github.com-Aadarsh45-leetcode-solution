class Solution {
public:
  typedef long long ll;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
      int n = nums.size();
      vector<ll>vec;
      unordered_map<int,ll> mp;
      priority_queue<pair<ll,int>> pq;
      
      for(int i =0;i<n;i++){
        mp[nums[i]]+=freq[i];
        pq.push({mp[nums[i]],nums[i]});
        while (!pq.empty())
            {
                pair<long long, int> p = pq.top();
                if (mp[p.second] != p.first)
                    pq.pop();
                else
                    break;
            }
        vec.push_back(pq.top().first);
        
      }
      return vec;
    }
};
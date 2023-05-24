class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums1.size();i++){
            v.push_back({nums2[i],nums1[i]});
        } 
        sort(v.rbegin(),v.rend());
        long long res = 0;
        long long curr = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        int i=0;
        while(i<nums1.size()){
            curr+=v[i].second;
            pq.push(v[i].second);
            if(i>=k-1){
                res=max(res,curr*v[i].first);
                curr-=pq.top();
                pq.pop();
            }
            i++;
        }
        return res;

    }
};
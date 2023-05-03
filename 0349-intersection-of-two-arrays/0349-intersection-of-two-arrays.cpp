class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,bool> is_present;
       vector<int>ans;
       for(int i=0; i<nums2.size(); i++)is_present[nums2[i]]=true;
       for(int i=0; i<nums1.size(); i++){
           if(is_present[nums1[i]]){
               is_present[nums1[i]]=false;
               ans.push_back(nums1[i]);
           }
       }
       return ans;
    }
};
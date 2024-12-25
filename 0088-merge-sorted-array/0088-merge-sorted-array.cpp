class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = n+m-1;
        int r = m-1;

        int last2 = n-1;
        while (last2 >= 0) {
            if (r >= 0 && nums1[r] > nums2[last2]) {
                nums1[last] = nums1[r];
                r--;
            } else {
                nums1[last] = nums2[last2];
                last2--;
            }
            last--;
        }

        
    }
};



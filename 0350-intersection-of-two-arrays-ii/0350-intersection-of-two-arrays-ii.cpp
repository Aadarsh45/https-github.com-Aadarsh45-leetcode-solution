class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count1, count2;
    vector<int> result;

    // Count frequencies of each element in nums1
    for (int num : nums1) {
        count1[num]++;
    }

    // Count frequencies of each element in nums2
    for (int num : nums2) {
        count2[num]++;
    }

    // Find the intersection
    for (const auto& pair : count1) {
        int num = pair.first;
        if (count2.find(num) != count2.end()) {
            int minCount = min(pair.second, count2[num]);
            for (int i = 0; i < minCount; ++i) {
                result.push_back(num);
            }
        }
    }

    return result;
    }
};
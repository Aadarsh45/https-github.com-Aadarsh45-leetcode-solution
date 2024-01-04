class Solution {
public:
    int minOperations(vector<int>& nums) {
       
    unordered_map<int, int> v;
    int ans = 0;

    for (int x : nums) {
        v[x]++;
    }

    for (auto& [x, y] : v) {
        if (y == 1) {
            return -1;
        } 
        else {
            ans = ans + ((y+ 2) / 3);
        }
    }

    return ans;
    }
};
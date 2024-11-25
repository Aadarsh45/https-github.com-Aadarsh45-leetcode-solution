class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
          int n = s.size();

        // Step 1: Check length divisibility
        if (n % k != 0) {
            return false;
        }

        int sub_len = n / k;

        // Step 2: Split strings into k equal-sized substrings
        vector<string> substrings_s, substrings_t;
        for (int i = 0; i < n; i += sub_len) {
            substrings_s.push_back(s.substr(i, sub_len));
            substrings_t.push_back(t.substr(i, sub_len));
        }

        // Step 3: Count frequency of substrings
        unordered_map<string, int> freq_s, freq_t;
        for (const string& sub : substrings_s) {
            freq_s[sub]++;
        }
        for (const string& sub : substrings_t) {
            freq_t[sub]++;
        }

        // Step 4: Compare frequency maps
        return freq_s == freq_t;
    }
};
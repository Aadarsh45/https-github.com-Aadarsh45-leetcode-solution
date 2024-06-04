class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> ump;
        for (char ch : s) {
            ump[ch]++;
        }
        int count = 0;
        bool hasOdd = false;

        for (auto& itr : ump) {
            if (itr.second % 2 == 0) {
                count += itr.second;
            } else {
                count += itr.second - 1;
                hasOdd = true;
            }
        }
        // If there is at least one odd count character, we can add one more character in the middle
        if (hasOdd) {
            count += 1;
        }

        return count;
    }
};
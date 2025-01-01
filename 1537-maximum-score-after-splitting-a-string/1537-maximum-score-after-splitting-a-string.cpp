class Solution {
public:
    int maxScore(string s) {
        int max_score = 0; for (size_t i = 1; i < s.length(); ++i) { std::string left = s.substr(0, i); std::string right = s.substr(i); int current_score = std::count(left.begin(), left.end(), '0') + std::count(right.begin(), right.end(), '1'); max_score = std::max(max_score, current_score); } return max_score;
    }
};
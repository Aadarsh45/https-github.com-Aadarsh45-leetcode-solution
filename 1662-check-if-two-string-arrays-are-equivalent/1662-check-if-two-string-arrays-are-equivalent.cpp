class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string left;
        string right;
        for(int i = 0; i < word1.size(); i++)
            left += word1[i];
        for(int i = 0; i < word2.size(); i++)
            right += word2[i];
        return left == right;
    }
};
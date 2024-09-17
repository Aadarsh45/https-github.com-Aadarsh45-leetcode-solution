class Solution {
public:
    vector<string> help(string s){
        stringstream ss(s); // Create a stringstream object
       string word;
    vector<string> words;

    while (ss >> word) { // Extract words from the sentence
        words.push_back(word);
    }
    return words;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> hash;
        vector<string>str1 = help(s1);
        vector<string>str2 = help(s2);

        for(auto it: str1){
            hash[it]++;
        }
        for(auto it: str2){
            hash[it]++;
        }
        vector<string> res;

        for(auto it: hash){
            if(it.second == 1){
                res.push_back(it.first);
            }
        }

        
        return res;
        
    }
};
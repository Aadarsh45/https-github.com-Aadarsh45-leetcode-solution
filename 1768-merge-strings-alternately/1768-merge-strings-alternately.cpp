class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        int i = 0, j =0;
        string s;
        
        while(i<n1 && j<n2){
            s+=word1[i];
            i++;
            s+=word2[j];
            j++;
        }
        
        while(i<n1){
            s+=word1[i];
            i++;
        }
        
        while(j<n2){
            s+=word2[j];
            j++;
        }
        
        return s;
    }
};
class Solution {
public:
    
    int isPrefixAndSuffix(string str1,string str2){
        
          if(str1.size()<=str2.size()){
            int j=0,i=0;
            while(i<str1.size()){ //&& j<str2.size()){
             //   cout<< "First while  str1[i] " <<str1[i]<< " str2[j] " <<str2[j]<< endl;
                if(str1[i++]!=str2[j++])
                    return 0;
                 if(i==str1.size())break;
            }
              
            i=str1.size()-1;j=str2.size()-1;
            while(i>=0){ //&& j>=str2.size()-str1.size()){
                cout<< "Second while str1[i] " <<str1[i]<< " str2[j] " <<str2[j]<< endl;
                if(str1[i--]!=str2[j--])
                    return 0;
                   if(i<0)break;
            }
           //   cout<< "->>> ans  == 1  str1  " << str1 <<  " str2 "<< str2<<  endl;
              return 1;
          }
        return 0;
        
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        // sort(words.begin(),words.end());
        int ans=0;
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
             // cout<< "main func words[i] " <<words[i]<< " words[j] " <<words[j]<< endl;
                ans+=isPrefixAndSuffix(words[i], words[j]);
                }
            
        }
        return ans;
    }
};
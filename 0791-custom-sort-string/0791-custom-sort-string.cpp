class Solution {
public:

string customSortString(string order, string s) {
     map<int,char>::iterator it;
     map<int,char>::iterator it2;
      map<char, int>hash;
      for(int i =0; i<order.length();i++){
        char temp = order[i];
        hash.insert({temp, i});
      }
      
      string ans = "";
      string rem = "";
  
      multimap<int, char> mp; 
      for(int i =0;i<s.length();i++){
        if(hash.find(s[i])!=hash.end()){
          auto it2 = hash.find(s[i]);
          int k = it2->second;
          mp.insert({k,s[i]});
        }
        else{
          rem+=s[i];
        }
      }
     vector<int>vec;
     for(auto it: mp){
       vec.push_back(it.first);
       cout<<it.first<<endl;
      
     }
  sort(vec.begin(),vec.end());
    
  
    for(int i =0;i<vec.size();i++){
      it = mp.find(vec[i]);
      cout<<it->first<<" "<<it->second<<endl;
      ans+=it->second;
    }
    
    ans+=rem;
    return ans;
    }
};
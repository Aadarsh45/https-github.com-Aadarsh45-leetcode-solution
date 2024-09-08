class Solution {
public:
    string help(int num)
{
    string str;
      while(num){
      if(num & 1) // 1
        str+='1';
      else // 0
        str+='0';
      num>>=1; // Right Shift by 1  
    }    
     reverse(str.begin(), str.end()); 
      return str;
}


    string convertDateToBinary(string s1) {
        string ans;
        int r = stoi(s1.substr(0, 4));
        int s = stoi(s1.substr(5, 2));
        int t = stoi(s1.substr(8, 2));

        ans+= help(r);
        ans+="-";
        ans+=help(s);
        ans+="-";
        ans+=help(t);

        
        return ans;
    }
};
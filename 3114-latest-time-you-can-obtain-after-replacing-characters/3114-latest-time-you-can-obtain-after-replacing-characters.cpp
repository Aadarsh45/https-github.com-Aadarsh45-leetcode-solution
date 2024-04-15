class Solution {
public:
    string findLatestTime(string s) {
        char hr1=s[0];
        char hr2=s[1];
        
        char min1=s[3];
        char min2=s[4];
        if(hr1=='?' && hr2=='?'){
            s[0]='1';
            s[1]='1';
        }
        else if(hr1=='?'){
            if(hr2=='0'|| hr2=='1')   s[0]='1';
            else    s[0]='0';
        }
        else if(hr2=='?'){
            if(hr1=='0')   s[1]='9';
            else    s[1]='1';
        }
        
        if(s[3]=='?' && s[4]=='?'){
            s[3]='5';
            s[4]='9';
        }
        else if(s[3]=='?'){
            s[3]='5';
        }
        else if(s[4]=='?'){
            s[4]='9';
        }
        return s;
        
        
    }
};
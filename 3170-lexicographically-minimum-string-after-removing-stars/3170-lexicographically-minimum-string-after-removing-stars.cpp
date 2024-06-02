class Solution {
    struct info{
        char c;
        int ind;
    };
    struct comp{
        bool operator()(const info& e1, const info& e2){
            if (e1.c==e2.c){
                return e1.ind < e2.ind;
            }
            return e2.c < e1.c;
        }
    };
public:
    string clearStars(string s) {
        
        int n = s.length();
       
        info temp;
        priority_queue<info,vector<info>,comp> pq;
        vector<char>v(n,'A');
        
        for(int i =0;i<n;i++){
            if(s[i] == '*'){
                   temp = pq.top();
                    pq.pop();
                    s[temp.ind] = '!';
                   continue;
             }
            temp.c = s[i];
            temp.ind = i;
            pq.push(temp);
        }
        if(pq.empty()) return "";
        
        
        string res = "";
        for (char c: s){
            if (c >= 'a') { 
                res += c; 
            }
        }
        return res;
        
        
    }
};


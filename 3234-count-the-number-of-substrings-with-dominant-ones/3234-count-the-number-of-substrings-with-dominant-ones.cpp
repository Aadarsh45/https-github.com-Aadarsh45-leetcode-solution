class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        
        vector<int>ones(n,0);
        vector<int>zero(n,0);
        if(s[0] == '1'){
            ones[0] = 1;
        }
        else{
            zero[0] = 1;
        }
        
        
        for(int i = 1;i<n;i++){
            if(s[i] == '1'){
                ones[i]= ones[i-1]+1;
            }
            else{
               ones[i]= ones[i-1];
            }
        }
        
        int i = 0;
        int j = 0;
        int output = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int one = ones[j]-((i == 0)?0:ones[i-1]); //count of one
                int count = j-i+1-one;  //count of zero
                
                if(count*count > one)  j+=((count*count)-one-1);
                
                if(count*count <= one) {
                    int kl = sqrt(one);
                    output++;
                    if(kl>count){  //again jump where zero can be greater than one.
                        output += (j+(kl-count))>=s.length()?(s.length()-j-1):(kl-count); //condition added just to ensure not to exceed the s.length()
                        j = j+(kl-count);
                    }
                }
            }
        }
        
        return output;
    }
};
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans=0;
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int n = colors.size();
        int count=1;
        for(int i=1;i<n;i++){
            if(colors[i]!=colors[i-1]){
                count++;
                if(count>=k){
                    ans++;
                }
            }
            else{
                count=1;
            }
        }
        return ans;}
};
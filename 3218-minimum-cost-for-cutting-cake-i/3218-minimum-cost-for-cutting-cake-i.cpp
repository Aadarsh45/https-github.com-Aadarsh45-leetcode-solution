class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hor, vector<int>& ver) {
        vector<pair<int,char>> vec;

        for(int i =0;i<hor.size();i++){
            vec.push_back({hor[i],'H'});
            
        }
        for(int j =0;j<ver.size();j++){
            vec.push_back({ver[j],'V'});
        }
        sort(vec.begin(),vec.end(),greater());
        
        int totalcost = 0;
        int v = 1;
        int h = 1;
        
        for(auto it: vec){
            int val = it.first;
            char c = it.second;
            
            
            if(c == 'H'){
                totalcost+=v*val;
                h++;
            }
            else{
                totalcost += h*val;
                v++;
            }
            cout<<val<<" "<<c<<" "<<totalcost<<endl;
        }
        return totalcost;
          
    }
};
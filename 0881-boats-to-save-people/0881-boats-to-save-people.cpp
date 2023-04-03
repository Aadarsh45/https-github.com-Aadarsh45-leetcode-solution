class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int cnt = 0;
        int lo=0;
        int hgh = people.size()-1;
        
        while(lo <= hgh){
            if(people[lo]+people[hgh] <= limit){
                lo++;
                 hgh--;
                
            }
            else{
                hgh--;
            }
            cnt++;
            
        }
        
        return cnt;
        
    }
};
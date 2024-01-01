class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin() , piles.end());
        
        // count of the pile which we will take 

        int count = piles.size()/3;

        // index of the pile from which we will start picking 

        int idx = piles.size()-2;

        int ans = 0;

        while( count--)
        {
              ans += piles[idx];
              idx -= 2;
        }

        return ans;
    }
};
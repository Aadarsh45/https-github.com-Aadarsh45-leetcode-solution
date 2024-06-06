class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
         if(hand.size() % groupSize != 0) return false;

        unordered_map<int,int> freq;

        for(auto &card: hand){

            freq[card]++;
            
        }

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &cards: freq){

            pq.push(cards.first);
            
        }

        while(!pq.empty()){
            int startCard = pq.top();

            for(int i=0; i<groupSize;i++){

                int currCard = startCard + i;

                if(freq[currCard] == 0) return false;

                freq[currCard]--;

                if(freq[currCard]==0) pq.pop();
                
            }
            
        }

        return true;
    }
};
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for (int i = 0; i < stones.size(); i++) {
           pq.push(stones[i]);
        }
        int temp;
        
        while(!pq.empty()){
             temp = pq.top();
             pq.pop();
             if(!pq.empty() && temp == pq.top()){
                pq.pop();
                if(pq.empty()){
                    return 0;
                }
            }
            else if(!pq.empty() && temp != pq.top()){
                int a = pq.top();
                pq.pop();
                pq.push(temp - a);
            }
            
        }
        return temp;
        
        
        
    }
};
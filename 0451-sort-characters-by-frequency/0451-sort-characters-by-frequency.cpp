class Solution {
public:
    string frequencySort(string s)  {
        map<char,int> mp;        // Create map for storing the frequency of each char in string
        for(auto it : s){
            mp[it]++;
        }
        priority_queue<pair<int,char>> pq;      // Create a max heap for sorting the map values based on frequency
        for(auto it : mp){
            pq.push({it.second,it.first});
        }
        string ans = "";                                  // start storing the chars in ans frequency wise
        while(!pq.empty()) {
            int freq = pq.top().first;                  // frequency count
            char ch = pq.top().second;                 // current char
            pq.pop();                                 // pop out the element
            for(int i=0;i<freq;i++)   {              // store the curr char (freq * 1 times)
                ans += ch;
            }
        }
        return ans;
    }
};
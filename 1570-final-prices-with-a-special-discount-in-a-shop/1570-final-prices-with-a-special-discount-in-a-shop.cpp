class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
    stack<int> stk;
    int n = prices.size();

    vector<int> res = prices; // Initialize res with the same size as prices
    
    for (int i = n - 1; i >= 0; i--) {
        while (!stk.empty() && stk.top() > prices[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            res[i] = prices[i] - stk.top();
        }
        stk.push(prices[i]);
    }

    return res;
}

};
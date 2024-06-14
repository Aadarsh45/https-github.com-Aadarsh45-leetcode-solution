class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
         int mod=pow(10,9)+7; // Since the answer may be very large, return it modulo 10'9 +7
        //inserting all the element in min_heap
        priority_queue<int , vector<int> , greater<int>> min_heap(nums.begin() , nums.end());
        //Use a min heap to hold all the numbers. Each time we do an operation, replace the top of the heap x by x + 1.
         while(k>0){
             int x = min_heap.top();
             min_heap.pop();
             x += 1;
             min_heap.push(x);
             k--;
         }
         long long int ans = 1;
         while(min_heap.size()){
             int temp = min_heap.top();
             min_heap.pop();
             ans = (ans * temp) % mod;
         }
         return ans;
    }
};
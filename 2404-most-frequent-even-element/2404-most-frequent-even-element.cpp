class Solution {
public:
   int mostFrequentEven(vector<int>& nums) {
    auto even_end = remove_if(begin(nums), end(nums), [](int n){ return n % 2; });
    sort(begin(nums), even_end);
    int cnt = 0, max_cnt = 0, res = -1;
    for (auto it = begin(nums); it != even_end; ++it) {
        cnt = it != begin(nums) && *it == *prev(it) ? cnt + 1 : 1;    
        res = max_cnt < cnt ? *it : res;
        max_cnt = max(max_cnt, cnt);
    }
    return res;
}
};
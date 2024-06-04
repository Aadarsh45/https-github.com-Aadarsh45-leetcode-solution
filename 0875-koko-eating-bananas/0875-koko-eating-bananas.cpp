class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            int total_hours = 0;
            for (int pile : piles) {
                total_hours += ceil((double)pile / mid);
            }
            if (total_hours > h) {
                left = mid + 1;
            }
             else {
                right = mid;
            }
        }
        return left;
    }
};
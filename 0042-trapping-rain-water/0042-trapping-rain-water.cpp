class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pre[i] = max(pre[i - 1], arr[i]);
        }

        vector<int> suff(n);
        suff[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], arr[i]);
        }

        int water = 0;
        for (int i = 0; i < n; i++) {
            int mini = min(pre[i], suff[i]);
            water += mini - arr[i];
        }
        return water;
    }
};

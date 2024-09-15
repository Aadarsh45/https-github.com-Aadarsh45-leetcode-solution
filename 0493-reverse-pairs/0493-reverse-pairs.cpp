class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr

        // storing elements in the temporary array in a sorted manner
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        // if elements on the right half are still left
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        // transferring all elements from temporary to arr
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int count_pairs(vector<int>& nums, int lo, int mid, int hgh) {
        int rgt = mid + 1;
        int cnt = 0;
        for (int i = lo; i <= mid; i++) {
            while (rgt <= hgh && (long long)nums[i] > 2 * (long long)nums[rgt]) rgt++;
            cnt += (rgt - (mid + 1));
        }
        return cnt;
    }

    int help(vector<int>& nums, int lo, int hgh) {
        if (lo >= hgh) return 0; // base condition for recursion
        int cnt = 0;
        int mid = lo + (hgh - lo) / 2;
        cnt += help(nums, lo, mid);
        cnt += help(nums, mid + 1, hgh);
        cnt += count_pairs(nums, lo, mid, hgh);
        merge(nums, lo, mid, hgh);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return help(nums, 0, nums.size() - 1);
    }
};

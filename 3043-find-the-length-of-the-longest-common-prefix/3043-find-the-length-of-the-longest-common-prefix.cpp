class Solution {
public:
    // Function for finding the length of a number
    int numLen(int num) {
        return to_string(num).length();
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixSet;

        // Iterate through the array
        for(int i : arr1) {

            // Store all possible prefixes of the number in prefixSet
            // e.g., For i -> 123, prefixSet here will store -> (123, 12, 1)

            while(i > 0) {
                prefixSet.insert(i);
                i /= 10;
            }
        }

        int res = 0;
        // Repeating the same process with arr2 
        for(int i : arr2) {

            // Find common prefixes using set and update result
            while(i > 0) {
                if(prefixSet.find(i) != prefixSet.end()) {
                    res = max(res, numLen(i));
                    break; // Once the largest common prefix is found, break out of the loop
                } 
                i /= 10;
            }
        }
        return res;
    }
};


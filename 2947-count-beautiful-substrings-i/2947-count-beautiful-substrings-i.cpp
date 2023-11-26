class Solution {
public:

    int beautifulSubstrings(string s, int k) {
        int len = s.length();
        int count = 0;

        // Loop through each character in the string
        for (int i = 0; i < len; i++) {
            int vow = 0; // Count of vowels
            int con = 0; // Count of consonants

            // Iterate through the string starting from index 'i'
            for (int j = i; j < len; j++) {
                char c = s[j];

                // Check if the character is a vowel, if so, increment the vowel count
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    vow++;
                }

                int df = j - i + 1; // Calculate the length of the current substring
                con = df - vow; // Calculate the count of consonants

                // Check if the count of vowels and consonants is equal and their product is divisible by 'k'
                if (vow == con && (vow * con) % k == 0) {
                    count++; // Increment the count if conditions are met
                }
            }
        }

        return count; // Return the count of beautiful substrings
    }
};
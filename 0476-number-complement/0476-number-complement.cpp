class Solution {
public:
    int findComplement(int num) {
        auto decimal_to_binary = [](int n) {
            if (n == 0) return std::string("0");
            std::string binary = "";
            while (n > 0) {
                binary = std::to_string(n % 2) + binary;
                n = n / 2;
            }
            return binary;
        };

        auto binary_to_decimal = [](const std::string &binary_str) {
            int decimal = 0;
            int n = binary_str.length();
            for (int i = 0; i < n; ++i) {
                if (binary_str[n - i - 1] == '1') {
                    decimal += (1 << i);  // Equivalent to 2^i
                }
            }
            return decimal;
        };

        std::string binary = decimal_to_binary(num);
        int n = binary.length();

        std::string complement = "";
        for (int i = 0; i < n; ++i) {
            if (binary[i] == '0') {
                complement += '1';
            } else {
                complement += '0';
            }
        }

        return binary_to_decimal(complement);
    }
};
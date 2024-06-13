class Solution {
public:
     
    bool rotateString(string s, string b) {
      std::string concatenated = s + s;
    // Check if b is a substring of concatenated
    return s.length()== b.length() && concatenated.find(b) != std::string::npos;
        
        
    }
};
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
    public:
  int rto(char a){//roman to integer
    switch(a){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return -1; // Handle invalid input
    }
}

    int romanToDecimal(string &str) {
        int n = str.length();
        int ans = 0;
        for(int i = 0; i<n; i++){
            if(i<n-1 && rto(str[i])<rto(str[i+1]))
                ans -= rto(str[i]);
            else
            ans += rto(str[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
int distinctSubsequences(string s)
{
    int n = s.size();
    int dp[n + 1];
    
    int mod = 1e9 + 7;
    dp[0] = 1;
    
    // Space : O(n)
    unordered_map <char, int> mp;
    
    // Time : O(n)
    for(int i = 1;i <= n;i++){
        
        dp[i] = (dp[i - 1] * 2) % mod;
        
        
        char c = s[i - 1];
        
        if(mp.find(c) != mp.end()){
            dp[i] = (dp[i] - dp[mp[c] - 1] + mod) % mod;
        }
        mp[c] = i;
    }
    
    return dp[n] % mod;
}


};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    using ll = long long int;
    string colName (long long int n)
    {
        // your code here
        
        string ans = "";
        while(n>0)
        {
            ll val = n%26;
                n = n/26;
            if(val==0)
            {
                ans.push_back('Z');
                n--;
            }
            else
            {
                char ch ='A' + val -1;
                ans.push_back(ch);
            }
        }
       
        reverse(ans.begin() ,ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends
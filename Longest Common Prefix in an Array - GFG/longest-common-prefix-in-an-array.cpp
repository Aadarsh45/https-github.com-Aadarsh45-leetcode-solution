//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  
  public:
    string compareStrings(string s,string t){
        int i=0,j=0;
        
        while(i<s.length() && j<t.length()){
            if(s[i] != t[j]){
                break;
            }
            i++;
            j++;
        }
        
        return s.substr(0,i);
    }
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string longest = arr[0];
        
        for(int i=1;i<N;i++){
            longest = compareStrings(longest,arr[i]);
        }
        if(longest.length() == 0) return "-1";
        return longest;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
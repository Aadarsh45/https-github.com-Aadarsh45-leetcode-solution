//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{  // Set bit count can be 0 .... 31
	    
	    for(int cnt = 0; cnt <= 31 ; cnt++){
	        
	        // Now target
	        
	        int target = n - cnt;
	        
	        if(target < 0) break;
	        
	        // Now checking whether the given target has a pop count as cnt
	        
	        int noSetBit = __builtin_popcount(target); 
	        
	        if(noSetBit == cnt){
	            return 0;
	        }
	        
	    }
	    
	    
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends
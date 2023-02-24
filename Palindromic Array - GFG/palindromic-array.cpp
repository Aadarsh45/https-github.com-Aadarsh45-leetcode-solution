//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/



/*Complete the function below*/
#include<vector>
class Solution {
public:
    bool ifCheck(vector<int>v){
        int i=0;
        int j=v.size()-1;
        while(i<j){
            if(v[i]!=v[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int PalinArray(int arr[], int n)
    {
    	// code here
    	vector<int>v;
    	for(int i=0; i<n; i++){
    	    int N=arr[i];
    	    while(N>9){
    	        v.push_back(N%10);
    	        N=N/10;
    	    }
    	    v.push_back(N);
    	    int c = ifCheck(v);
    	    if(!c)
    	        return c;
    	    else
    	        v.clear();
    	}
	return 1;
   }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends
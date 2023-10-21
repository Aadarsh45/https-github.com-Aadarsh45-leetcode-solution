//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         vector<vector<int>>ans;
         sort(intervals.begin(),intervals.end());

         
         ans.push_back(intervals[0]);
         int fix=0;
         int st_idx=0;
         for(int i=1;i<intervals.size();i++){
             
             if(ans[fix][1]>=intervals[i][0]){//overlap
                //merge it
                if(ans[fix][1]<intervals[i][1]){

                    //update ans vector 

                    //extending its range
                    ans.pop_back();
                    vector<int>temp;
                    temp.push_back(intervals[st_idx][0]);
                    temp.push_back(intervals[i][1]);
                    ans.push_back(temp);
                }
                
                
             }
             
             //no merge
             else{
                 ans.push_back(intervals[i]);
                 //to track the previous intervals index
                 st_idx=i;
                 fix++;
             }
         }
         
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
class Solution {
public:
    int n;
    vector<int> max_idx;//array storing index for max
    int left=0;
    void print(){
        cout<<"[";
        for(int i=left; i<max_idx.size(); i++) 
            cout<<max_idx[i]<<",";
        cout<<"]\n";
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        n=nums.size();       
        vector<int> ans(n-k+1);

        for(int i=0; i<n; i++){
            // max_idx using elements from index=left on 
            while(max_idx.size()>left && nums[i]>=nums[max_idx.back()]) 
                max_idx.pop_back();// pop back the indexes for smaller ones
            max_idx.push_back(i);  // push back the index for larger one

            if (max_idx[left]==i-k) // index=i-k should not in the window
                left++;  //move left
        //    cout<<left;
        //    print();
            if (i>=k-1){
                ans[i-k+1]=nums[max_idx[left]]; //Max element for this window
        //        cout<<"->"<<ans[i-k+1]<<endl;
            }        
        }
        return ans;
    }
};
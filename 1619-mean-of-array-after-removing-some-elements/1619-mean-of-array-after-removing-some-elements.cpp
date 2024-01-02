class Solution {
public:
    double trimMean(vector<int>& arr) {
     //sort the vector 
      sort(arr.begin(),arr.end());
        
      double size = arr.size();
        
      long double sum = 0;
        
      double toBeRemoved = (5*size)/100;
        
      for(int i=toBeRemoved ; i < size - toBeRemoved ; ++i) {
          sum += arr[i];
      }
      double remainingElements = size-2*toBeRemoved;
      return sum/remainingElements;
    }
};
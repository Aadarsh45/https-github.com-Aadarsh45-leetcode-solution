//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

import java.util.HashMap; 
import java.util.Map; 
import java.util.Map.Entry; 


// } Driver Code Ends
//User function Template for Java

class Info {
        int data;
        int idx;
        public Info(int data,int idx){
            this.data=data;
            this.idx=idx;
        }
    }
class Solution{
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    
    public static int[] sortA1ByA2(int A1[], int N, int A2[], int M)
    {  // creating map where we are store the storted pattern of A2
    // why map :: beacuse it allowed min time to search the things whether it is present or not
    
        HashMap<Integer,Integer> map=new HashMap<>();
       for(int i=0;i<M;i++){
           map.put(A2[i],i);
       }
       // we are also using the pq where we are storing the element present in A1 in sorted order following the A2 order
       
       PriorityQueue<Info> pq=new PriorityQueue<>((x,y)-> x.idx-y.idx);
      // int check=0;
       int temp[]=new int[N];// for element not present in A2[]
       int k=0;
       for(int i=0;i<N;i++){
           if(map.containsKey(A1[i])){
              // check=1;
               pq.add(new Info(A1[i],map.get(A1[i])));
           }
           else {
               //System.out.print(A1[i]);
               temp[k++]=A1[i];// add t=in temp we sort it in future
           }
       }
       Arrays.sort(temp,0,k);// sort the specfifc part of the temp array 
      int ans[]=new int[N];
     int j=0;
     while(!pq.isEmpty()){// now remove from queue and fill in ans
         ans[j++]=pq.remove().data;
     }
     for(int i=0;i<k;i++){
         ans[j++]=temp[i];
     }
     return ans;
     
    }
}



//{ Driver Code Starts.
class Main {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int t=sc.nextInt();
		
		while(t-->0)
		{
		    int n=sc.nextInt();
		    int m=sc.nextInt();
		    int a1[]=new int[n];
		    int a2[]=new int[m];
		    
		    for(int i=0;i<n;i++)
		    a1[i]=sc.nextInt();
		    
		    for(int i=0;i<m;i++)
		    a2[i]=sc.nextInt();
		    Solution ob=new Solution();
		    a1 = ob.sortA1ByA2(a1,n,a2,m);
		    for(int x:a1)
		    System.out.print(x+" ");
		    
		    System.out.println();
		}
	}
	

}



// } Driver Code Ends
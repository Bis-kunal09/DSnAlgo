// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to return maximum sum subarray by removing at most one element.
    int maxSumSubarray(int A[], int n)
    {   
        // int flag=true;
    //     int mini=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         if(A[i]>0){
    //             flag=false;
    //             break;
    //         }
    //         mini=max(A[i],mini);
    //     }
    //     if(flag==true){
    //         return mini;
    //     }
    //     int ltor[n];
    //     int maxi=0;
    //     int bestmax=0;
    //     for(int i=0;i<n;i++){
    //         maxi=max(maxi,A[i]+maxi);
    //         ltor[i]=maxi;
    //         bestmax=max(bestmax,maxi);
    //     }
    //     int rtol[n];
    //     int raxi=0;
    //     int bestrmax=0;
    //     for(int i=n-1;i>=0;i--){
    //         raxi=max(raxi,A[i]+raxi);
    //         rtol[i]=raxi;
    //         bestrmax=max(bestrmax,raxi);
    //     }
    //     int l=bestrmax;
    //     for(int i=1;i<n-1;i++){
    //         l=max(l,rtol[i+1]+ltor[i-1]);
    //     }
    //     return l;
     int fw[n]; fw[0] = A[0];
       int curr_max = A[0], max_so_far = A[0];
       
       for(int i=1; i<n; i++){
           curr_max = max(A[i],curr_max+A[i]);
           max_so_far = max(max_so_far,curr_max);
           fw[i] = curr_max;
       }
       
       int bw[n];
       max_so_far = curr_max = bw[n-1] = A[n-1];
       for(int i=n-2; i>=0; i--){
           curr_max = max(A[i],curr_max+A[i]);
           max_so_far = max(max_so_far,curr_max);
           bw[i] = curr_max;
       }
       
       int ans = max_so_far;
       for(int i=1; i<n-1; i++){
           ans = max(ans,fw[i-1]+bw[i+1]);
       }
       
       return (ans);
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	
	//taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking total elements
		int n;
		cin>>n;
		int a[n];
		
		//inserting elements in the array
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		
		//calling method maxSumSubarray()
		Solution obj;
		cout<<obj.maxSumSubarray(a,n)<<endl;
	}
}

  // } Driver Code Ends
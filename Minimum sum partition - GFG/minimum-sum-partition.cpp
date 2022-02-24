// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	    }
	    vector<vector<bool>> dp(n,vector<bool> (sum+1,0));
	    for(int i=0;i<n;i++){
	        dp[i][0]=1;
	    }
	    if(sum>arr[0]){
	        dp[0][arr[0]]=1;
	    }
	    for(int i=1;i<n;i++){
	        for(int j=1;j<=sum;j++){
	            int take=0;
	            if(arr[i]<=j){
	                take=dp[i-1][j-arr[i]];
	            }
	            int notake=dp[i-1][j];
	            dp[i][j]=take||notake;
	            
	        }
	    }
	    int mini=1e9;
	    for(int i=0;i<=sum/2;i++){
	        int s1;
	        if(dp[n-1][i]){
	            s1=sum-i;
	            mini=min(mini,abs(i-s1));
	        }
	        
	        
	    }
	    return mini;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
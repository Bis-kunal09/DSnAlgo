// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        
	    
	    int dp[m+1][n+1];
	    for(int i=0;i<=m;i++){
	        for(int j=0;j<=n;j++){
	            if(i==0||j==0){
	                dp[i][j]=0;
	            }
	        }
	    }
	    int maxi=0;
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=n;j++){
	            if(S2[i-1]==S1[j-1]){
	                dp[i][j]=dp[i-1][j-1]+1;
	                maxi=max(maxi,dp[i][j]);
	                
	               
	                
	            }
	            else{
	                
	                dp[i][j]=0;
	            }
	        }
	        
	    }
	   
	    return maxi;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    
         string B=str;
        reverse(B.begin(),B.end());
        int m=str.size();
	    int n=B.size();
	    
	    int dp[m+1][n+1];
	    for(int i=0;i<=m;i++){
	        for(int j=0;j<=n;j++){
	            if(i==0||j==0){
	                dp[i][j]=0;
	            }
	        }
	    }
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=n;j++){
	            if(str[i-1]==B[j-1]){
	                dp[i][j]=dp[i-1][j-1]+1;
	            }
	            else{
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    int lcs= dp[m][n];
	    int todel=str.size()-lcs;
	    return todel;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends
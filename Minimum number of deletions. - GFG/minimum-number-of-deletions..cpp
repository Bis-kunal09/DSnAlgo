// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}// } Driver Code Ends


int minDeletions(string str, int n) { 
     string B=str;
        reverse(B.begin(),B.end());
        int m=str.size();
	    int n1=B.size();
	    
	    int dp[m+1][n1+1];
	    for(int i=0;i<=m;i++){
	        for(int j=0;j<=n1;j++){
	            if(i==0||j==0){
	                dp[i][j]=0;
	            }
	        }
	    }
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=n1;j++){
	            if(str[i-1]==B[j-1]){
	                dp[i][j]=dp[i-1][j-1]+1;
	            }
	            else{
	                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    int lcs= dp[m][n1];
	    return n-lcs;
} 
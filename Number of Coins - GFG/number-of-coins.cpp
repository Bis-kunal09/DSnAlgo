// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
// 	int minCoins(int coins[], int M, int V) 
// 	{ 
// 	    vector<vector<int>> dp(M+1,vector<int>(V+1));
	    
// 	    for(int i=0;i<=M;i++){
// 	        dp[i][0]=0;
// 	    }
	    
// 	    for(int i=0;i<=V;i++){
// 	        dp[0][i]=INT_MAX-1;
	        
	        
// 	    }
// 	    for(int i=1;i<=V;i++){
// 	        if(i%coins[0]==0){
// 	            dp[1][i]=i/coins[0];
// 	        }
// 	        else{
// 	            dp[1][i]=INT_MAX-1;
// 	        }
// 	    }
	    
// 	    for(int i=2;i<=M;i++){
// 	        for(int j=1;j<=V;j++){
// 	            int take=0;
// 	            int notake=dp[i-1][j];
// 	            if(coins[i-1]<=j){
// 	                take=dp[i][j-coins[i-1]]+1;
// 	            }
// 	            dp[i][j]=min(take,notake);
// 	            cout<<dp[i][j]<<" ";
	            
// 	        }
// 	        cout<<endl;
// 	    }
// 	    return dp[M][V];
// 	} 
	int minCoins(int coins[], int M, int V) 
{ 
      int W = V;
    int n = M;
    int dp[n+1][W+1];
    
    for(int i=0 ; i< n+1 ; i++){
        for(int j=0 ; j< W+1 ; j++){
            if(j == 0)
                dp[i][j] = 0;
            if(i == 0)
                dp[i][j] = INT_MAX -1;
        }
    }
    for(int i=1 ; i< n+1 ; i++){
        for(int j=1 ; j< W+1 ; j++){
            if(coins[i-1] <= j)
                dp[i][j] = min(1 + dp[i][j-coins[i-1]] , dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W]==INT_MAX-1?-1:dp[n][W];
}
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
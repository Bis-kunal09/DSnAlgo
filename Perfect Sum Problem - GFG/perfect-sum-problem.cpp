// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{   int mod=1e9+7;
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        if(arr[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
        }
        for(int i=1;i<n;i++){
            dp[i][0]=1;
        }
        if(arr[0]!=0&&arr[0]<=sum){
            dp[0][arr[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int take=0;
                if(arr[i]<=j){
                    take=dp[i-1][j-arr[i]];
                }
                int notake=dp[i-1][j];
                dp[i][j]=(take+notake)%mod;
            }
        }
        return dp[n-1][sum]%mod;
	}
// 	int perfectSum(int arr[], int N, int sum)
//     {
//         int dp[N + 1][sum + 1];
        
//         for(int i = 0; i <= N; i++)
//         {
//             dp[i][0] = 1;
//         }
        
//         for(int j = 1; j <= sum; j++)
//         {
//             dp[0][j] = 0;
//         }
        
//         for(int i = 1; i <= N; i++)
//         {
//             for(int j = 1; j <= sum; j++)
//             {
//                 if(j -  arr[i - 1] < 0)
//                 {
//                     dp[i][j] = dp[i - 1][j];
//                 }
//                 else
//                 {
//                     dp[i][j] = (dp[i - 1][j] + dp[i - 1][j -  arr[i - 1]]) % 1000000007;
//                 }
//             }
//         }
        
//         return dp[N][sum];
//     }  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
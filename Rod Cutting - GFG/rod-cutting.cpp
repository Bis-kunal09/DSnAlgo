// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> length(n);
        for(int i=0;i<n;i++){
            length[i]=i+1;
        }
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int take=0;
                int notake=dp[i-1][j];
                if(length[i-1]<=j){
                    take=dp[i][j-length[i-1]]+price[i-1];
                    
                }
                dp[i][j]=max(notake,take);
            }
        }
        return dp[n][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int dp[n][m];
        for(int i=0;i<n;i++){
            dp[i][0]=M[i][0];
        }
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                int a=INT_MIN;
                if(i>=1){
                    a=M[i][j]+dp[i-1][j-1];
                }
                int b=INT_MIN;    
                if(i<n-1){   
                    b=M[i][j]+dp[i+1][j-1];
                }
                int c=M[i][j]+dp[i][j-1];
                dp[i][j]=max(a,max(b,c));
            }
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(dp[i][m-1],maxi);
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
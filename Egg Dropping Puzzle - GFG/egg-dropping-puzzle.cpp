// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int solve(int n,int k){
        if(k==1||k==0){
            return k;
        }
        if(n==1){
            return k;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int mini=INT_MAX;
        for(int l=1;l<=k;l++){
            int temp=1+max(solve(n-1,l-1),solve(n,k-l));
            mini=min(temp,mini);
        }
        return dp[n][k]= mini;
    }
    int eggDrop(int n, int k) 
    {   memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
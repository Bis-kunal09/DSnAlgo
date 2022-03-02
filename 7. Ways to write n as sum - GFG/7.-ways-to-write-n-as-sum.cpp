// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count the number of different ways in which n can be 
    //written as a sum of two or more positive integers.
    int numberOfWays(int coins[],int numberOfCoins,int value)
    {   int n=numberOfCoins;
        int dp[n+1][value+1];
        for(int i=0;i<=value;i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=value;j++){
                int notake=dp[i-1][j];
                int take=0;
                if(coins[i-1]<=j){
                    take=dp[i][j-coins[i-1]];
                }
                dp[i][j]=take+notake;
            }
        }
        return dp[n][value];
        
    }
    int countWays(int n)
    {   
        int arr[n-1];
        for(int i=0;i<n-1;i++){
            arr[i]=i+1;
        }
        return numberOfWays(arr,n-1,n);
        
    }
};

// { Driver Code Starts.
// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.countWays(n)<<endl;
    }
    return 0;
}  // } Driver Code Ends
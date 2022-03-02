// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
   
    long long numberOfWays(int coins[],int numberOfCoins,int value)
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
};


// { Driver Code Starts.


int main() {
    
    //taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //inserting coins to the array
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function numberOfWays
	    cout<<obj.numberOfWays(coins,numberOfCoins,value)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
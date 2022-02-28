// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Complete this function

class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
    {
        
        vector<vector<long long>> dp(numberOfCoins,vector<long long>(value+1,0));
        for(int i=0;i<=value;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
            else{
                dp[0][i]=1e9;
            }
        }
        
        for(int i=1;i<numberOfCoins;i++){
            for(int j=0;j<=value;j++){
                int take=1e9;
                int notake=dp[i-1][j];
                if(j>=coins[i]){
                    take=dp[i][j-coins[i]]+1;    
                    
                }
                dp[i][j]=min(take,notake);
                
            }
        }
        int ans=dp[numberOfCoins-1][value];
        if(ans>=1e9){
            return -1;
        }
        return ans;
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
	    
	    //taking value of each coin
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function minimumNumberOfCoins()
	    int answer=obj.minimumNumberOfCoins(coins,numberOfCoins,value);
	    
	    //printing "Not Possible" if answer is -1
	    //else printing answer
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
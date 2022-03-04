// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int f(int n){
        if(n==1||n==0){
            return 1;
        }
        int single=f(n-1);
        int couple=(n-1)*f(n-2);
        return single+couple;
    }
    // int countFriendsPairings(int n) 
    // {   int dp[n+1];
    //     int mod=1e9+7;
    //     dp[2]=2;
    //     dp[1]=1;
    //     for(int i=3;i<=n;i++){
    //         dp[i]=(dp[i-1]+((i-1)*dp[i-2]))%mod;
    //     }
    //     return dp[n]%mod;
    // }
     int countFriendsPairings(int n) 
   { 
       // code here
       int m=1e9+7;
       int dp[n+1];
       dp[0]=0;
       dp[1]=1;
       dp[2]=2;
       for(long long int i=3;i<n+1;i++)
       {
           dp[i]=(dp[i-1]+dp[i-2]*(i-1))%m;
       }
       return dp[n]%m;
       
       
   } 
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends
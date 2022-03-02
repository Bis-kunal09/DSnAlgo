// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.
    int dp[1000000];
    long long f(int m){
        if(m==0||m==1){
            return 1;
        }
        if(dp[m]!=-1){
            return 0;
        }
        int one=f(m-1);
        int two=0;
        if(m>1){
            two=f(m-2);
            
        }
        return dp[m]= one+two;
    }
    long long countWays(int m)
    {
        memset(dp,-1,sizeof(dp));
        return m/2+1;
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}  // } Driver Code Ends
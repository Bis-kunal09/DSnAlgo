// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSubsetSum(int N, int arr[], int sum){
        vector<vector<bool>> dp(N,vector<bool>(sum+1,false));
        for(int i=0;i<N;i++){
            dp[i][0]=false;
        }
        if(arr[0]<=sum){
            dp[0][arr[0]]=true;    
        }
        
        for(int i=1;i<N;i++){
            for(int j=1;j<=sum;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(arr[i]<=j){
                    take=dp[i-1][j-arr[i]];
                }
                dp[i][j]=take||nottake;
            }
        }
        return dp[N-1][sum];
    }
    int equalPartition(int N, int arr[])
    {   int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        return isSubsetSum(N,arr,sum/2);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
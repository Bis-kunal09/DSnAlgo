// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of jumps to reach the end of the array.
    int dp[100000];
    int f(int arr[],int n){
        if(n==1){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans=INT_MAX;
        for(int i=0;i<=n-2;i++){
            if(i+arr[i]>=n-1){
                int mini=INT_MAX;
                mini=minimumJumps(arr,i+1);
                if(mini!=INT_MAX){
                    ans=min(ans,mini+1);
                }
            }
        }
        return dp[n]= ans;
    }
    int minimumJumps(int arr[], int n){
        int maxi=arr[0];
        int step=arr[0];
        int jumps=1;
        if(n==1){
            return 0;
        }
        else if(arr[0]==0){
            return -1;
        }
        else{
            for(int i=1;i<n;i++){
                if(i==n-1){
                    return jumps;
                }
                maxi=max(maxi,arr[i]+i);
                step--;
                if(step==0){
                    jumps++;
                    if(i>=maxi){
                        return -1;
                    }
                    step=maxi-i;
                }
            
            }
        }
        
        
        
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking count of testcases
    int t;
    cin>>t;
    while(t--)
    {
        
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minimumJumps(arr, n)<<endl;    // Function to calculate minimum number of jumps
    }
    return 0;
}  // } Driver Code Ends
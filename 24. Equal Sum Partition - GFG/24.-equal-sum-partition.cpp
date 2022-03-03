// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++


class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    
    bool knap(int arr[],int n,int sum){
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(arr[0]<=sum){
            dp[0][arr[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool nopick=dp[i-1][j];
                bool pick=false;
                if(j>=arr[i]){
                    pick=dp[i-1][j-arr[i]];
                }
                dp[i][j]=pick||nopick;
            }
        }
        return dp[n-1][sum];
        
    }
    bool findPartition(int a[], int n)
    {
    
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        if(sum%2!=0){
            
            return false;
        }
        return knap(a,n,sum/2);
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking total testcases
    int tc;
    cin >> tc;
    while (tc--) {
        
        //taking size of array
        int n, i;
        cin >> n;
        int a[n];
        
        //inserting elements in the array
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (ob.findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
  // } Driver Code Ends
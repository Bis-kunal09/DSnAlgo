// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[500+1][500+1];
    bool ispalindrome(string str,int i,int e){
        while(i<=e){
            if(str[i]==str[e]){
                i++;
                e--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int solve(string str,int i,int j){
        if(i>=j){
            return 0;
        }
        if(ispalindrome(str,i,j)){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mini=1e9;
        for(int k=i;k<j;k++){
            int left=0;
            int right=0;
            if(dp[i][k]!=-1){
                 left= dp[i][k];
            }
            else{
                left=solve(str,i,k);
                
            }
            if(dp[k+1][j]!=-1){
                 right=dp[k+1][j];
            }
            else{
                right=solve(str,k+1,j);
                
            }
            int temp=left+right+1;
            mini=min(mini,temp);
            
        }
        return dp[i][j]=mini;
    }
    int palindromicPartition(string str)
    {   memset(dp,-1,sizeof(dp));
        int n=str.size();
        return solve(str,0,n-1);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
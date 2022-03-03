// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to return the maximum sum without adding adjacent elements
    int dp[10000];
    int f(int arr[],int n){
        if(n==0){
            return arr[0];
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int pick=arr[n]+f(arr,n-2);
        int nopick=f(arr,n-1);
        return dp[n]= max(pick,nopick);
    }
    long long maximumSum(int arr[], int sizeOfArray)
    {
        vector<int> dp(sizeOfArray);
        int flag=true;
        int mini=INT_MIN;
        for(int i=0;i<sizeOfArray;i++){
            if(arr[i]>0){
                flag=false;
            }
            mini=max(mini,arr[i]);
        }
        if(flag==true){
            return mini;
        }
        dp[0]=max(0,arr[0]);
        dp[1]=max(dp[0],arr[1]);
        for(int i=2;i<sizeOfArray;i++){
            int take=arr[i];
            
                take+=dp[i-2];
            
            int notake=dp[i-1];
            dp[i]=max(take,notake);
        }
        return dp[sizeOfArray-1];
    }
};

// { Driver Code Starts.


int main() {
    
    //taking total testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking size of array
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    //inserting elements in the array
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    Solution ob;
	    //calling function maximumSum()
	    cout<<ob.maximumSum(arr,sizeOfArray)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
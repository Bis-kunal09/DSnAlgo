// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int dp[10001];
    int maximizeTheCut(int n, int x, int y, int z)
    {
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int a=INT_MIN;
        if(n>=x){
            a=maximizeTheCut(n-x,x,y,z);
        }
        int b=INT_MIN;
        if(n>=y){
            b=maximizeTheCut(n-y,x,y,z);
        }
        int c=INT_MIN;
        if(n>=z){
            c=maximizeTheCut(n-z,x,y,z);
        }
        return dp[n]=max(a,max(b,c))+1;
    }
    int maximizeTheCuts(int n, int x, int y, int z){
        memset(dp,-1,sizeof(dp));
        int ans= maximizeTheCut(n,x,y,z);
        if(ans<0)
            return 0;
        return ans;    
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
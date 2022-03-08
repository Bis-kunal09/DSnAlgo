// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long getCount(int N)
	{  long long dp[N+1][10]={0};
	   
	   vector<vector<int>> arr{{0,8},{1,2,4},{1,2,3,5},{3,2,6},{1,4,5,7},{2,4,5,6,8},{6,3,5,9},{7,4,8},{8,5,7,9,0},{9,8,6}};
	   for(int i=0;i<=9;i++){
	       dp[0][i]=0;
	   }
	   for(int i=1;i<=N;i++){
	       for(int j=0;j<=9;j++){
	           if(i==1){
	               dp[i][j]=1;
	           }
	           else{
	               for(int x:arr[j]){
	                   dp[i][j]+=dp[i-1][x];
	                   
	               }
	           }
	           
	       }
	   }
	   long long sum=0;
	   for(int j=0;j<=9;j++){
	       sum+=dp[N][j];
	       
	   }
	   return sum;
	   
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
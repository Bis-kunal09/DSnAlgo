// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int f(int a,int b){
        if(a==1&&b==1){
            return 1;
        }
        
        int left=0;
        if(a>0){
            left=NumberOfPath(a-1,b);
        }
        int right=0;
        if(b>0){
             right=NumberOfPath(a,b-1);
        }
        
        return left+right;
    }
    int NumberOfPath(int a, int b)
    {   
        int DP[a][b];
       for(int i=0;i<a;i++){
           for(int j=0;j<b;j++){
               if(i==0 or j==0) DP[i][j]=1;
               else DP[i][j]=DP[i][j-1] + DP[i-1][j];
           }
       }
       return DP[a-1][b-1];
        
    }
};


// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends
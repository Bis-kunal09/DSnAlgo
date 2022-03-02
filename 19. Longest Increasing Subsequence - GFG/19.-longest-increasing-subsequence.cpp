// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int cel(vector<int> lis,int s,int n){
        int e=lis.size()-1;
        while(s<e){
            int m=s+(e-s)/2;
            if(lis[m]>=n){
                e=m;
            }
            else{
                s=m+1;
            }
        }
        return e;
    }
    int longestSubsequence(int n, int a[])
    {
       vector<int> lis;
       lis.push_back(a[0]);
       for(int i=0;i<n;i++){
           if(a[i]>lis[lis.size()-1]){
               lis.push_back(a[i]);
           }
           else{
               int c=cel(lis,0,a[i]);
               lis[c]=a[i];
           }
       }
       return lis.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to print the maximum contiguous subarray sum ending at each 
    //position in the array and return the overall maximum.
    long long maximumSum(int arr[], int sizeOfArray)
    {
       vector<int> v(sizeOfArray);
       v[0]=arr[0];
       int maxi=arr[0];
       int total=arr[0];
       cout<<v[0]<<" ";
       for(int i=1;i<sizeOfArray;i++){
           v[i]=max(arr[i],maxi+arr[i]);
           
           maxi=v[i];
           total=max(total,maxi);
           cout<<v[i]<<" ";
       }
       cout<<endl;
       
       return total;
       
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
	    
	    //inserting elements to the array
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    Solution ob;
	    //calling function maximumSum()
	    cout<<ob.maximumSum(arr,sizeOfArray)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
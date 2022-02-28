// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <fstream>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
// You need to complete this function


class Solution
{
    public:
    //Function to find the nth fibonacci number using bottom-up approach.
    unordered_map<int,long long> mp;
    long long f(int number){
         if(number==2||number==1){
            return 1;
        }
        if(mp.find(number)!=mp.end()){
            return mp[number];
        }
        return mp[number]=findNthFibonacci(number-1)+findNthFibonacci(number-2);
    }
    long long findNthFibonacci(int number)
    {
       
       return f(number);
        
    }
};

// { Driver Code Starts.

int main()
 {
    //taking testcases
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        //taking nth fibonacci 
        //to be found
        int number;
        cin>>number;
        
        //calling function findNthFibonacci()
        //and passing number as parameter
        Solution obj;
        cout<<obj.findNthFibonacci(number)<<endl;
    }
    
	return 0;
}
  // } Driver Code Ends
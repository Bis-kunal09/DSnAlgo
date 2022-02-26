// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    bool isStepping(int n){
        vector<int> c;
        int a=n;
        if(n>=0&&n<=10){
            return true;
        }
        while(n>0){
            c.push_back(n%10);
            n/=10;
            
        }
        bool flag=true;
        for(int i=1;i<c.size();i++){
            if(abs(c[i-1]-c[i])!=1){
                flag=false;
            }
        }
        return flag;
    }
    int steppingNumbers(int n, int m)
    {   int count=0;
        for(int i=n;i<=m;i++){
            if(isStepping(i)==true){
                count++;
            }
        }
        return count;
    }
};


// { Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}

  // } Driver Code Ends
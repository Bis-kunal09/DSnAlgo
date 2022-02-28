// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string,int> mp;
    int mod=1003;
    int solve(string s,int i,int j,bool istrue){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(istrue){
                if( s[i]=='T'){
                    return 1;   
                }
                else{
                    return 0;
                }
            }
            else{
                if( s[i]=='F'){
                    return 1;   
                }
                else{
                    return 0;
                }
            }
        }
        string temp=to_string(i)+" "+to_string(j)+" "+to_string(istrue);
        if(mp.find(temp)!=mp.end()){
            return mp[temp];
        }
        int ans=0;
        for(int k=i+1;k<j;k+=2){
            int lt=solve(s,i,k-1,true);
            int lf=solve(s,i,k-1,false);
            int rt=solve(s,k+1,j,true);
            int rf=solve(s,k+1,j,false);
             if(s[k] == '&')
               {
                   if(istrue == true)
                   ans = ((ans % mod) + (lt*rt)%mod) % mod;
                   else
                   ans = ((ans % mod) + (lt*rf)% mod + (lf * rt)% mod + (lf * rf))% mod;
               }
             else if(s[k] == '|')
               {
                   if(istrue == true)
                    ans = ((ans % mod) + (lt*rt)% mod + (lf*rt)% mod + (lt *rf))% mod;
                   else
                    ans = ((ans % mod) + (lf*rf));
               }
             else
               {
                   if(istrue == true)
                   ans = ((ans % mod) + (lt*rf)% mod + (lf*rt))% mod;
                   else
                    ans = ((ans % mod) + (lt*rt)% mod + (lf*rf))% mod;
               }
               
            
        }
        mp[temp]=ans;
        return mp[temp];
        
    }
    int countWays(int N, string S){
        
        return solve(S,0,N-1,true);
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
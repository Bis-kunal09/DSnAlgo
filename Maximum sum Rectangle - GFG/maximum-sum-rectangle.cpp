// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadane(vector<int> ans,int c){
        int maxi=INT_MIN;
        int check=0;
        for(int i=0;i<c;i++){
            check+=ans[i];
            if(check>maxi){
                maxi=check;
            }
            if(check<0){
                check=0;
            }
        }
        return maxi;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int maxi=INT_MIN;
        for(int i=0;i<R;i++){
            vector<int> ans(C);
            for(int j=i;j<R;j++){
                for(int k=0;k<C;k++){
                    ans[k]+=M[j][k];
                }
                maxi=max(maxi,kadane(ans,C));
                
            }
        }
        return maxi;
        
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends
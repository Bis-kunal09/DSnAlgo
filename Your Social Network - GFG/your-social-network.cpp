// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    string socialNetwork(int arr[], int n) {
        vector<vector<int>> v(n+1, vector<int> (n+1, 0));
        
        //traversing to parent node and updating it to the current node.
        for(int i = 2; i < n+1; i++) {
            v[i][arr[i-2]] = 1;
            for(int j = 1; j < i; j++) {
                if(v[arr[i-2]][j] != 0) v[i][j] = v[arr[i-2]][j] + 1;
            }
        }
        
        string ans = "";
        for(int i = 2; i < n+1; i++) {
            for(int j = 1; j < i; j++) {
                if(v[i][j] != 0) ans += to_string(i) + " " + to_string(j) + " " + to_string(v[i][j]) + " ";
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N-1];
        for(int i=0; i<N-1; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.socialNetwork(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends
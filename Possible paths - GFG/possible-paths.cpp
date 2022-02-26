// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

// class Solution {
//   public:
// // 	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
// // 	   unordered_map<int, vector<int>> g;
// // 	   int r=graph.size();
// // 	   int c=graph[0].size();
// // 	   for(int i=0;i<r;i++){
// // 	       for(int j=0;j<c;j++){
// // 	           if(graph[i][j]==1){
// // 	               g[i].push_back(j);
// // 	           }
// // 	       }
// // 	   }
	   
      
// //         int ans = 0;
// //         int ans1=0;
// //         queue<int> q;
// //         q.push(u); 
// //         int steps =0; 
// //         while(!q.empty()){
// //             int n = q.size();
// //             ans++;
// //             for(int i=0; i<n; ++i){
// //                 int curr=q.front();q.pop();
// //                 if(curr == v&&ans-1==k) ans1++ ;   
// //                 for(auto x:  g[curr]){             
                   
// //                     q.push(x);
                   
// //                 }
// //             }
// //           if(ans > k) break;
// //         }
// //         int mod=1e9;
// //         return ans1%mod;
        
        
// // 	}
// 	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k)
//     {
//       int m =1e9 ;
//       int n =graph.size();  
      
//       vector<vector<int>> dp(n,vector<int>(k+1,0));
      
//       dp[u][0] = 1;
//       for(int j=0; j<k; j++){
//         for(int i=0; i<n; i++){
//           if(dp[i][j] > 0){
//              for(int l=0; l<n; l++)
//                 if(graph[i][l]==1)dp[l][j+1] = (dp[l][j+1]+dp[i][j])%m;
//           }
//         }   
//       }

//       return dp[v][k]%m;
//     }
	  
        
    

// };
class Solution {
    int dfs(vector<vector<int>>&graph, vector<vector<long>>&dp, int cur, int target, int k) {
        if(dp[cur][k] != -1) {
            return dp[cur][k];
        }
        dp[cur][k] = 0;
        for(int i=0; i<graph.size(); i++) {
            if(graph[cur][i]) {
                dp[cur][k] = (dp[cur][k] + dfs(graph, dp, i, target, k-1))%int(1e9+7);
            }
        }
        return dp[cur][k];
    }
  public:
	int MinimumWalk(vector<vector<int>>&graph, int u, int v, int k){
	    vector<vector<long>> dp(graph.size(), vector<long>(k+1, -1));
	    dp[v][0] = 1;
	    for(int i=0; i<graph.size(); i++) {
	        if(i != v) dp[i][0] = 0;
	    }
	    dfs(graph, dp, u, v, k);
	    return dp[u][k];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>graph(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> graph[i][j];
			}
		}
		int u, v, k;
		cin >> u >> v >> k;
		Solution obj;
		int ans = obj.MinimumWalk(graph, u, v, k);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
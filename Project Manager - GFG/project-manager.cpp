// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


 // } Driver Code Ends
class Solution{
    public:
    // int minTime(vector<pair<int, int>> &dependency, int duration[], int n, int m) {
    //     vector<vector<int>> g(n,vector<int> (n));
    //     vector<int> indegree(n);
    //     vector<int> someans(n);
    //     for(int i=0;i<m;i++){
    //         g[dependency[i].first].push_back(dependency[i].second);
        
    //         indegree[dependency[i].second]++;
    //         // someans[dependency[i].first]=duration[dependency[i].first];
    //     }
    //     queue<int> q;
    //     for(int i=0;i<indegree.size();i++){
    //         if(indegree[i]==0){
    //             someans[i]=duration[i];
    //             q.push(i);
    //         }
    //     }
    //     int count=0;
    //     vector<int> ans;
    //     while(!q.empty()){
        
    //             int node=q.front();
    //             q.pop();
    //             count++;
    //             for(auto x:g[node]){
    //                 indegree[x]--;
    //                 someans[x]=max(someans[x],someans[node]);
    //                 if(indegree[x]==0){
    //                     q.push(x);
    //                     someans[x]+=duration[x];
                        
    //                 }
    //             }
            
    //     }
    //     return (count==n)?*max_element(someans.begin(),someans.end()):-1;
        
    // }
    int minTime(vector<pair<int, int>> &d, int dur[], int n, int m) {
	vector<int> indeg(n, 0), topo, dp(n, 0), adj[n];
	queue<int> q;
	for(int i=0;i<m;i++)indeg[d[i].second]++,adj[d[i].first].push_back(d[i].second);
	for (int i = 0; i < n; i++)if (indeg[i] == 0)q.push(i), dp[i] = dur[i];
	while (!q.empty()) {
		auto x = q.front(); q.pop();
		topo.push_back(x);
		for (auto v : adj[x]) {
			dp[v] = max(dp[v], dur[v] + dp[x]);
			if (--indeg[v]==0)q.push(v);
		}
	}
	if (topo.size() != n)return -1; // contains cycle !!!
	return *max_element(dp.begin(), dp.end());
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, x, y;
        cin >> n >> m;
        int duration[n + 5];
        vector<pair<int, int>> dependency;
        for (int i = 0; i < n; i++) cin >> duration[i];
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            dependency.push_back({x, y});
        }
        Solution obj;
        cout << obj.minTime(dependency, duration, n, m) << endl;
    }
    return 0;
}  // } Driver Code Ends
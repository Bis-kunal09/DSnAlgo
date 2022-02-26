// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    string exercise(int N, int M, vector<vector<int>> A, int src, int dest, int X){
        unordered_map<int, vector<pair<int,int>>> g;
        for(auto x:A){
            g[x[0]].push_back({x[1],x[2]});
             g[x[1]].push_back({x[0],x[2]});
            
        }
        vector<int> dis(N,1e9);
        dis[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
    
        pq.push({0,src});
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            for(auto x:g[u]){
                int v=x.first;
                int wt=x.second;
                if(dis[v]>dis[u]+wt){
                    
                    dis[v]=dis[u]+wt;
                    pq.push({dis[v],v});
                    
                    
                }
                
            }
        }
        
        if(dis[dest]>X){
            return "Neeman's Wool Joggers";
        }
        
        return "Neeman's Cotton Classics";
        
        
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, M, src, dest, X;
        cin >> N >> M >> src >> dest >> X;
        vector<vector<int>> A(M, vector<int> (3, 0));
        for(int i = 0; i < M; i++){
            cin >> A[i][0] >> A[i][1] >> A[i][2];
        }
        Solution obj;
        cout << obj.exercise(N, M, A, src, dest, X) << "\n";
    }
}
  // } Driver Code Ends
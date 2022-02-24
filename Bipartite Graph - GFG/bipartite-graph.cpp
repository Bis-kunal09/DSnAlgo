// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int i,vector<int> adj[],vector<int> &color){
        
        if(color[i]==-1){
            color[i]=1;
        }
        
        for(auto x:adj[i]){
            if(color[x]==-1){
                color[x]=1-color[i];
                if(!dfs(x,adj,color)){
                    return false;
                }
            }
            else if(color[i]==color[x]){
                return false;
            }
        }
        return true;
        
        
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V,0);
	    vector<int> color(V,-1); 
	    
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(!dfs(i,adj,color)){
	                return false;
	            }
	        }
	            
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
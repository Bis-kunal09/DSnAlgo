// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    vector<vector<int>> dp(N,vector<int>(N,0));
	    int tx=TargetPos[0]-1;
	    int ty=TargetPos[1]-1;
	    int cx=KnightPos[0]-1;
	    int cy=KnightPos[1]-1;
	    
	    queue<pair<int,int>> q;
	    q.push({cx,cy});
	    int steps=0;
	    int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[8] = {-1, 1, 1, -1, 2, -2, 2, -2};
	    while(!q.empty()){
	        int k=q.size();
	         steps++;
	       
	        while(k--){
	            int x=q.front().first;
	            int y=q.front().second;
	           
	            q.pop();
	            if(x==tx&&y==ty){
	                return steps-1;
	            }
	            for(int l=0;l<=8;l++){
	                if(x+dx[l]<0||x+dx[l]>=N||y+dy[l]<0||y+dy[l]>=N||dp[x+dx[l]][y+dy[l]]==1){
	                    continue;
	                }
	                dp[x+dx[l]][y+dy[l]]=1;
	                q.push({x+dx[l],y+dy[l]});
	            }
	        }
	    }
	    return -1;
	    
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
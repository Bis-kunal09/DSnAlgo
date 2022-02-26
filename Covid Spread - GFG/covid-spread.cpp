// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int helpaterp(vector<vector<int>> hospital)
    {   int r=hospital.size();
        int c=hospital[0].size(); 
        vector<vector<int>> vis(r,vector<int>(c,0));
        queue<pair<int,int>> q;
        int count=0;
        int total=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(hospital[i][j]==2){
                    q.push({i,j});
                    
                }
                if(hospital[i][j]!=0){
                    total++;
                }
            }
        }
        int days=0;
        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            int k=q.size();
            days++;
            while(k--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                count++;
                for(int i=0;i<4;i++){
                    int tx=x+dx[i];
                    int ty=y+dy[i];
                    if(tx>=r||tx<0||ty>=c||ty<0||vis[tx][ty]==1||hospital[tx][ty]!=1){
                        continue;
                    }
                    q.push({tx,ty});
                    vis[tx][ty]=1;
                    hospital[tx][ty]=2;
                    
                }
            }
        }
        if(count==total){
            return days-1;
        }
        
        return -1;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
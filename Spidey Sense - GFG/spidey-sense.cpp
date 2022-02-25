// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

    public:
    
    vector<vector<int> > findDistance(vector<vector<char> >& matrix, int M, int N) 
    { 
       vector<vector<int>> g(M,vector<int>(N,-1));
       int r=M;
       int c=N;
       queue<pair<int,int>> q;
       for(int i=0;i<r;i++){
           for(int j=0;j<c;j++){
               if(matrix[i][j]=='B'){
                   q.push({i,j});
                   g[i][j]=0;
               }
               
           }
       }
       int x[4]={0,0,-1,1};
       int y[4]={-1,1,0,0};
       while(!q.empty()){
           int size=q.size();
           while(size--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    if(i+x[k]<0||i+x[k]>=r||j+y[k]<0||j+y[k]>=c||matrix[i+x[k]][j+y[k]]=='W'){
                        continue;
                    }
                    if(matrix[i+x[k]][j+y[k]]=='O'){
                        g[i+x[k]][j+y[k]]=g[i][j]+1;
                        q.push({i+x[k],j+y[k]});
                        matrix[i+x[k]][j+y[k]]='Z';
                        
                    }
                }
               
           }
          
           
       }
       return g;
       
    } 
};

// { Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}  // } Driver Code Ends
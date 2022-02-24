class Solution {
public:
    //brute force with die
    vector<int> findquad(int val,int n){
        vector<int> ans;
        int r=(val-1)/n;
        int c=(val-1)%n;
        int x=n-1-r;
        int y=r%2==0?c:n-1-c;
        
        
            ans.push_back(x);
            ans.push_back(y);
        
        return ans;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int steps=0;
        int size=board.size();
        queue<int> q;
        q.push(1);
        vector<vector<bool>> vis(board.size(),vector<bool>(board.size(),false));
        vis[size-1][0]=true;
        
        while(!q.empty()){
            int l=q.size();
            
            while(l--){
                int val=q.front();
                
                
                if(val==size*size){
                    return steps;
                }
                q.pop();
                for(int k=1;k<=6;k++){
                    int temp=val;
                    temp+=k;
                    cout<<temp<<" ";
                    if(temp>size*size){
                        break;
                    }
                    vector<int> a=findquad(temp,size);
                    
                    
                    if(vis[a[0]][a[1]]==true){
                        
                        continue;
                    }
                    vis[a[0]][a[1]]=true;
                    if(board[a[0]][a[1]]==-1){
                        q.push(temp);
                        cout<<"("<<temp<<")"<<a[0]<<a[1]<<"P";
                        
                        
                    }
                    else{
                        
                        q.push(board[a[0]][a[1]]);
                        
                    }
                    
                }
            }
            steps++;
        }
        return -1;
    }
};
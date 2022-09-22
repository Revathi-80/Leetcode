class Solution {
    private:
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
           vis[row][col]=1;
           int n=grid.size();
           int m=grid[0].size();
           queue<pair<int,int>>q;
           q.push({row,col});
        
           while(!q.empty()){
               int row=q.front().first;
               int col=q.front().second;
               q.pop();
               int arr[]={0,-1,0,1,0};
               for(int i=0;i<4;i++){
                   
                   int nrow=row+arr[i];
                   int ncol=col+arr[i+1];
                   
                       if(ncol>=0 && ncol<m && nrow>=0 && nrow<n
                         && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                           vis[nrow][ncol]=1;
                           q.push({nrow,ncol});
                       }
               }  
               
           }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int row=0;row<n; row++){
            for (int col=0 ; col<m ;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
        
    }
};
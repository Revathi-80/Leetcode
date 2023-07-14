class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) {
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        
       
        int cnt=0;
        int tm=0;
        while(!q.empty()){
            int row= q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            int delrow[] = {-1,0,1,0};
            int delcol[] ={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nrow= delrow[i]+row;
                int ncol=delcol[i]+col;
                if(nrow>=0 && nrow<n &&ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1) {
                    vis[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                    cnt++;
                }
            }
            
        }
        if(fresh!=cnt) return -1;
        return tm;
    }
};
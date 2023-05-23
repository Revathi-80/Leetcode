class Solution {
    void dfs(vector<vector<char>>&board,vector<vector<int>>&vis,int row,int col,int delrow[] ,int delcol[]){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++) {
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] 
              && board[nrow][ncol]=='O') {
                dfs(board,vis,nrow,ncol,delrow,delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O')
                dfs(board,vis,0,j,delrow,delcol);
        }
        for(int j=0;j<m;j++){
            if(!vis[n-1][j] && board[n-1][j]=='O')
                dfs(board,vis,n-1,j,delrow,delcol);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O')
                dfs(board,vis,i,0,delrow,delcol);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && board[i][m-1]=='O')
                dfs(board,vis,i,m-1,delrow,delcol);
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                if(!vis[i][j]) {
                    board[i][j]='X';
                }
            }
        }
    }
};
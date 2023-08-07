class Solution {
    int paths(vector<vector<int>>&grid, int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0 ) return dp[i][j]=grid[i][j];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=paths(grid,i-1,j,dp);
        int left=paths(grid,i,j-1,dp);
        return dp[i][j]=grid[i][j]+ min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                if(i==0 && j==0)
                    dp[i][j]=grid[i][j];
                else {
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=grid[i][j] +min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
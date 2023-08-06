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
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return paths(grid,n-1,m-1,dp);
    }
};
class Solution {
    int paths(vector<vector<int>>&grid,int i,int j,int n,vector<vector<int>>&dp) {
        if(j<0 || j>=n) return 1e9;
        if(i==0) return grid[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=0;k<n;k++) {
            if(k!=j) {
                mini =min(mini,grid[i][j]+paths(grid,i-1,k,n,dp));
            }
        }
        return dp[i][j]=mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n =grid.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,paths(grid,n-1,j,n,dp));
        }
        return mini;
    }
};
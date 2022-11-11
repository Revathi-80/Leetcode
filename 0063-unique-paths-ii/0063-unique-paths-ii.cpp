class Solution {
    int count(int i,int j,vector<vector<int>>&dp, vector<vector<int>>&obstacleGrid){
        if(i==0 && j==0)
            return 1;
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1 )
            return 0;
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
            int left=count(i,j-1,dp,obstacleGrid);
            int up=count(i-1,j,dp,obstacleGrid);
        
        return dp[i][j]=left+up;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m= obstacleGrid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //count(n-1,m-1,dp,obstacleGrid);
        dp[0][1]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(!obstacleGrid[i-1][j-1]){
                    int up=dp[i-1][j];
                     int left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        
        
        return dp[n][m];
    }
};
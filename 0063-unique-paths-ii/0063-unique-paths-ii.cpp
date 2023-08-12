class Solution {
    int paths(vector<vector<int>>&obstacleGrid,int i, int j,vector<vector<int>>&dp) {
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = paths(obstacleGrid,i-1,j,dp);
        int left = paths(obstacleGrid,i,j-1,dp);
        return dp[i][j]=up+left;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n= obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return paths(obstacleGrid,n-1,m-1,dp); 
    }
};
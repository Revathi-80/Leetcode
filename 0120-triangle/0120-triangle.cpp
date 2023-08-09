class Solution {
    int paths (vector<vector<int>>&triangle, int i, int j,int n,vector<vector<int>>&dp) {
       
        if(i == n-1) return triangle[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down= triangle[i][j] + paths(triangle,i+1,j,n,dp);
        int diagonal=triangle[i][j] +paths(triangle,i+1,j+1,n,dp);
        return dp[i][j]=min(down,diagonal);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<m;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--) {
            for(int j=i;j>=0;j--) {
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};
class Solution {
    // int paths(vector<vector<int>>&matrix , int i, int j,int n,vector<vector<int>>&dp){
    //     if(j<0 || j>=n) return 1e9;
    //     if(i==0) return matrix[0][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int left= matrix[i][j] + paths(matrix,i-1,j-1,n,dp);
    //     int up=matrix[i][j] + paths(matrix,i-1,j,n,dp);
    //     int right = matrix[i][j] + paths(matrix,i-1,j+1,n,dp);
    //     return dp[i][j]=min(up,min(left,right));
    // }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int left=1e9,right=1e9;
                int up=matrix[i][j] + dp[i-1][j];
                if(j-1>=0) left=matrix[i][j] + dp[i-1][j-1];
                if(j+1<n) right= matrix[i][j] + dp[i-1][j+1];
                dp[i][j]= min(up,min(left,right));
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
    }
};
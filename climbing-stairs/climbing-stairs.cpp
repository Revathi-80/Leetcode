class Solution {
    int stairs(int ind,vector<int>&dp){
        if(ind<=1)
            return 1;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=stairs(ind-1,dp)+stairs(ind-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return stairs(n,dp);
    }
};
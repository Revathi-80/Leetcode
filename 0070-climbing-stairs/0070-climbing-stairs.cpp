class Solution {
    int func(int ind , vector<int>&dp){
        if(ind<=1) return dp[ind]=1;
        if(dp[ind]!=-1) return dp[ind];
        int lh=func(ind-1,dp);
        int rh=func(ind-2,dp);
        
        return dp[ind]=lh+rh;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=1,dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
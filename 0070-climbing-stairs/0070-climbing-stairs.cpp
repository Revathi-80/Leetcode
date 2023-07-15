class Solution {
    int func(int n,vector<int>&dp){
        if(n<=1) return dp[n]=1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=func(n-1,dp)+func(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int prev2=1,prev=1;
        for(int i=2;i<=n;i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
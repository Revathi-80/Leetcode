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
        // vector<int>dp(n+1,-1);
       int prev2=1,prev=1;
        for(int i=2;i<=n;i++){
            // dp[i]=dp[i-1]+dp[i-2];
            int curr= prev2+prev;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
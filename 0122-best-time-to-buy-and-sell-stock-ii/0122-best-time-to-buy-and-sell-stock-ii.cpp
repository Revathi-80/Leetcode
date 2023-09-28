class Solution {
    int f(vector<int>&prices,int ind,int buy,int n ,vector<vector<int>>&dp) {
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit=0;
        if(buy) {
            profit = max(-prices[ind] + f(prices,ind+1,0,n,dp),
                        0 + f(prices,ind+1,1,n,dp));
        }
        else {
            profit = max(prices[ind] + f(prices,ind+1,1,n,dp),
                        0 + f(prices,ind+1,0,n,dp));
        }
        return dp[ind][buy]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--) {
            for(int buy=0;buy<=1;buy++) {
                int profit=0;
                if(buy) {
                    profit= max(-prices[ind] + dp[ind+1][0],
                               0+ dp[ind+1][1]);
                }
                else {
                    profit = max(prices[ind] + dp[ind+1][1],
                                0 + dp[ind+1][0]);
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }
};
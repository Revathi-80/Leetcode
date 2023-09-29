class Solution {
    int f(vector<int>&prices,int ind,int buy,int n,int fee,vector<vector<int>>&dp) {
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy) {
            return max(-prices[ind]+f(prices,ind+1,0,n,fee,dp),
                      0 + f(prices,ind+1,1,n,fee,dp));
        }
        else {
            return max(prices[ind] + f(prices,ind+1,1,n,fee,dp)-fee,
                      0 + f(prices,ind+1,0,n,fee,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--) {
            for(int buy=0;buy<=1;buy++) {
                if(buy) {
                    dp[ind][buy] = max(-prices[ind] + dp[ind+1][0],
                                      0 + dp[ind+1][1]);
                }
                else{
                    dp[ind][buy] = max(prices[ind]-fee+dp[ind+1][1],
                                       0 +dp[ind+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
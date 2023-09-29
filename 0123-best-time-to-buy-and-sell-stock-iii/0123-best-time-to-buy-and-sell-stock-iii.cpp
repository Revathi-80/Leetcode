class Solution {
    int f(vector<int>&prices,int n,int ind,int tran ,vector<vector<int>>&dp) {
        if(ind==n || tran==4) return 0;
        if(dp[ind][tran]!=-1) return dp[ind][tran];
        if(tran%2==0) {
            return dp[ind][tran]=max(-prices[ind] +f(prices,n,ind+1,tran+1,dp),
                       0 + f(prices,n,ind+1,tran,dp));
        }
        else {
            return dp[ind][tran]=max(prices[ind] + f(prices,n,ind+1,tran+1,dp),
                       0 + f(prices,n,ind+1,tran,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        
        for(int ind=n-1;ind>=0;ind--) {
            for(int tran=3;tran>=0;tran--) {
                if(tran%2==0) {
                     dp[ind][tran]=max(-prices[ind] +dp[ind+1][tran+1],
                       0 + dp[ind+1][tran]);
                }
                else {
                     dp[ind][tran]=max(prices[ind] + dp[ind+1][tran+1],
                       0 + dp[ind+1][tran]);
                 }
            }
        }
        
        return dp[0][0];
    }
};
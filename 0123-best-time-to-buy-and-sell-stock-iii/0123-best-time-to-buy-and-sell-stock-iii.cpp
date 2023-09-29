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
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return f(prices,n,0,0,dp);
    }
};
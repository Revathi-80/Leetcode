class Solution {
    int f(int ind,int tran,int k,int n,vector<int>&prices,vector<vector<int>>&dp) {
        if(ind==n || tran==2*k) return 0;
        if(dp[ind][tran]!=-1) return dp[ind][tran];
        if(tran%2==0) {
            return dp[ind][tran]=max( -prices[ind] + f(ind+1,tran+1,k,n,prices,dp),
                      0 + f(ind+1,tran,k,n,prices,dp));
        }
        else {
            return dp[ind][tran]=max( prices[ind] + f(ind+1,tran+1,k,n,prices,dp),
                      0 + f(ind+1,tran,k,n,prices,dp));
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,-1));
        return f(0,0,k,n,prices,dp);
    }
};
class Solution {
    int f(vector<int>&prices,int ind,int buy,int n, vector<vector<vector<int>>>&dp,int cnt) {
        if(ind==n || cnt==0 ) return 0;
        if(dp[ind][buy][cnt]!=-1) return dp[ind][buy][cnt];
        int profit=0;
        if(buy) {
            profit = max(-prices[ind]+ f(prices,ind+1,0,n,dp,cnt),
                        0 + f(prices,ind+1,1,n,dp,cnt));
        }
        else {
            profit= max( prices[ind] + f(prices,ind+1,1,n,dp,cnt-1),
                       0 + f(prices,ind+1,0,n,dp,cnt));
        }
        return dp[ind][buy][cnt]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(prices,0,1,n,dp,2);
    }
};
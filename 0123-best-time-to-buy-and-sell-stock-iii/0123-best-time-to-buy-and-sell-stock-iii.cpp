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
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        for(int ind=n-1;ind>=0;ind--) {
            for(int buy=0;buy<=1;buy++) {
                for(int cnt=1;cnt<=2;cnt++) {
                    int profit=0;
                    if(buy) {
                        dp[ind][buy][cnt] = max( -prices[ind] + dp[ind+1][0][cnt],
                                    0 + dp[ind+1][1][cnt]);
                    }
                    else {
                        dp[ind][buy][cnt] = max(prices[ind] + dp[ind+1][1][cnt-1],
                                    0 + dp[ind+1][0][cnt]);
                        
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }
};
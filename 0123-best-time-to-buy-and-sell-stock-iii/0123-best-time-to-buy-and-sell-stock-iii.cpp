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
        vector<vector<int>>ahead(2,vector<int>(3,0));
         vector<vector<int>>curr(2,vector<int>(3,0));
        
        for(int ind=n-1;ind>=0;ind--) {
            for(int buy=0;buy<=1;buy++) {
                for(int cnt=1;cnt<=2;cnt++) {
                    if(buy) {
                        curr[buy][cnt] = max( -prices[ind] + ahead[0][cnt],
                                    0 + ahead[1][cnt]);
                    }
                    else {
                        curr[buy][cnt] = max(prices[ind] + ahead[1][cnt-1],
                                    0 + ahead[0][cnt]);
                        
                    }
                }
            }
            ahead=curr;
        }
        
        return ahead[1][2];
    }
};
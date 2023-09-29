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
```
​
​
**Another approach  dp[N] x[4] **
​
​
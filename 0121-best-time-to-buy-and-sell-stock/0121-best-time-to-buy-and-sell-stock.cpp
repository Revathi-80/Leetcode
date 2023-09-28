class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int s=prices[0],profit=0;
        for(int i=1;i<n;i++) {
            if(prices[i]<s) {
                s=prices[i];
            }
            profit=max(profit,prices[i]-s);
        }
        return profit;
    }
};
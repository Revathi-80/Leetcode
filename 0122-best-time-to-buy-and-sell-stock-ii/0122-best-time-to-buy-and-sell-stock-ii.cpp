class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       int prevbuy=0,prevNotBuy=0,currBuy,currNotBuy;
        for(int ind=n-1;ind>=0;ind--) {
                
            currBuy= max(-prices[ind] + prevNotBuy,
                               0+ prevbuy);
               
            currNotBuy= max(prices[ind] + prevbuy,
                                0 + prevNotBuy);
                
            prevbuy=currBuy;
            prevNotBuy= currNotBuy;
        }
        return prevbuy;
    }
};
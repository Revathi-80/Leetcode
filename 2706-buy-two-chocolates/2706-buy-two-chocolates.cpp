class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int ans= INT_MAX;
        int n=prices.size();
        int cost=money;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 cost =prices[i]+prices[j];
                if(cost < ans) {
                    cout<<cost<<" "<<money-cost<<endl;
                    ans=cost;
                }
            }
        }
        
        return (ans>money?money:(money-ans));
    }
};
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0;
        for(int cost:costs) {
            if(cost<=coins) {
                cnt++;
                coins-=cost;
            }
        }
        return cnt;
    }
};
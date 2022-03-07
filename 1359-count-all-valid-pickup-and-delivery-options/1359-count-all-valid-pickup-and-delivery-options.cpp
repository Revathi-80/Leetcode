class Solution {
public:
    int countOrders(int n) {
         long long dp[501];
        dp[1]=1L;
        dp[2]=6L;
        long long M =1000000007;
        for(int i=3;i<=n;i++){
            long long  num=2*i-1;
            long long total= ((num*(num+1))/2);
            dp[i]=(dp[i-1]*total)%M;
        }
        return (int)dp[n];
    }
};
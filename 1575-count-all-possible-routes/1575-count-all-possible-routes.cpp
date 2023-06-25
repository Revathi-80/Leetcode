class Solution {
    int cnt (vector<int>&locations, int ind, int finish,int fuel,vector<vector<int>>&dp) {
        if(fuel<0 ) {
            return 0;
        }
        int n=locations.size();
        if (dp[ind][fuel]!=-1) return dp[ind][fuel];
        int ans= ind==finish ?1:0;
        for (int i=0;i<n;i++){
            if(i!=ind) {
                ans = (ans + cnt(locations,i,finish,fuel-abs(locations[ind]-locations[i]),dp))%1000000007;
            }
        }
        return dp[ind][fuel]=ans;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n=locations.size();
        vector<vector<int>>dp(n,vector<int>(fuel+1,-1));
        return cnt(locations,start,finish,fuel,dp);
    }
};
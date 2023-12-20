class Solution {
    int func(int ind,vector<int>&nums,vector<int>&dp) {
        if(ind<0) return 0;
        if(ind==0) return nums[0];
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind] + func(ind-2,nums,dp);
        int notpick = func(ind-1,nums,dp);
        return dp[ind]=max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,-1);
        return func(n-1,nums,dp);
    }
};
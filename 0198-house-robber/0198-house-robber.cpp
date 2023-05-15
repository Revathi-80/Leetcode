class Solution {
    int maxi(vector<int>&nums,int ind,vector<int>&dp) {
        if(ind==0) return nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind]+maxi(nums,ind-2,dp);
        int not_pick= maxi(nums,ind-1,dp);
        return dp[ind]=max(pick,not_pick);
    }
public:
    int rob(vector<int>& nums) {
         int n=nums.size();
        vector<int>dp(n+1,-1);
       
        return maxi(nums,n-1,dp);
    }
};
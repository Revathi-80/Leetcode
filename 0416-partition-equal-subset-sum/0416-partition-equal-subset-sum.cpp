class Solution {
    bool func(vector<int>&nums, int ind,int sum,int target,vector<vector<int>>&dp) {
        if(sum==target) return true;
        if(sum==0) return false;
        if(ind==0) return (target+nums[0])==(sum-nums[0]);
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool nottake= func(nums,ind-1,sum,target,dp);
        bool take = false;
        if(sum>=nums[ind]) 
            take= func(nums,ind-1,sum-nums[ind],target+nums[ind],dp);
        return dp[ind][sum]=take || nottake;
        
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return func(nums,n-1,sum,0,dp);
    }
};
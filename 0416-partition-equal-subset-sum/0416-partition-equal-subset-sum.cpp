class Solution {
    bool func(vector<int>&nums, int ind,int target,vector<vector<int>>&dp) {
        if(target==0) return true;
        if(ind==0) return nums[0]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool nottake= func(nums,ind-1,target,dp);
        bool take = false;
        if(target>=nums[ind]) 
            take= func(nums,ind-1,target-nums[ind],dp);
        return dp[ind][target]=take || nottake;
        
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%2!=0) return false;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        
        return func(nums,n-1,sum/2,dp);
    }
};
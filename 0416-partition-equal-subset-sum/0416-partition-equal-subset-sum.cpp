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
        int target=sum/2;
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=target) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool  nottake= dp[i-1][j];
                bool take=false;
                if(j>=nums[i])
                    take=dp[i-1][j-nums[i]];
                dp[i][j] = take || nottake;
            }
        }
        
        return dp[n-1][target];
    }
};
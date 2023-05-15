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
         dp[0]=nums[0];
        for(int i=1;i<n;i++) {
            int pick=nums[i];
            if(i>1)
                pick+=dp[i-2];
            int not_pick=dp[i-1];
            dp[i]=max(pick,not_pick);
        }
        return dp[n-1];
    }
};
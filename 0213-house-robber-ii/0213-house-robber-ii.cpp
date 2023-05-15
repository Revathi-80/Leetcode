class Solution {
    int maxi(vector<int>&temp, int ind, vector<int>&dp) {
        if(ind==0) return temp[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=temp[ind]+ maxi(temp,ind-2,dp);
        int not_pick= maxi(temp,ind-1,dp);
        return dp[ind]=max(pick,not_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
     vector<int>temp1;
        vector<int>temp2;
        for(int i=0;i<n;i++) {
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=n-1)
                temp2.push_back(nums[i]);
        }
        int sz1=temp1.size();
        vector<int>dp1(sz1+1,-1);
        int sz2=temp2.size();
        vector<int>dp2(sz2+1,-1);
        return max(maxi(temp1,sz1-1,dp1),maxi(temp2,sz2-1,dp2));
    }
};
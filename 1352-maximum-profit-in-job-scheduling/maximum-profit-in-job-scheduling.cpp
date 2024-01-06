class Solution {
    int func(int ind, vector<vector<int>>&arr,int n,vector<int>&dp,vector<int>&startTime) {
        if(ind==n) return 0;
        // don't pick
    
        if(dp[ind]!=-1) return dp[ind];
        int j= lower_bound(startTime.begin(),startTime.end(),arr[ind][1])- startTime.begin();
      int  res = max(func(ind+1,arr,n,dp,startTime)
        ,arr[ind][2] + func(j,arr,n,dp,startTime));
    return dp[ind]=res;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n= startTime.size();
        vector<vector<int>>arr;
        for(int i=0;i<startTime.size();i++) {
            arr.push_back({startTime[i],endTime[i],profit[i]});
        }   
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            startTime[i]= arr[i][0];
        }
        vector<int>dp(n+1,-1);
        return func(0,arr,n,dp,startTime);
    }
};
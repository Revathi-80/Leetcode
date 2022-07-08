class Solution {
public:
    void subset(vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds,int ind, int n){
        ans.push_back(ds);
        for(int i=ind;i<n;i++){
        if(i!=ind && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            subset(nums,ans,ds,i+1,n);
            ds.pop_back();
       
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        subset(nums,ans,ds,0,n);
        return ans;
    }
};
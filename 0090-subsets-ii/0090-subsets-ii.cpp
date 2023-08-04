class Solution {
    void generate(vector<int>&nums,int ind,int n,vector<int>&ds,vector<vector<int>>&ans) {
            ans.push_back(ds);
        for(int i=ind;i<n;i++){
            if(i!=ind && nums[i]==nums[i-1]) continue;
            //pick
            ds.push_back(nums[i]);
            generate(nums,i+1,n,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        generate(nums,0,n,ds,ans);
        return ans;
    }
};
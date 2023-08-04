class Solution {
    void generate(vector<int>&nums, int ind, vector<int>&ds,int n,vector<vector<int>>&ans) {
        if(ind>=n){
            ans.push_back(ds);
            return; 
        }
        //pick
        ds.push_back(nums[ind]);
        generate(nums,ind+1,ds,n,ans);
        ds.pop_back();
        generate(nums,ind+1,ds,n,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        int n=nums.size();
        vector<vector<int>>ans;
        generate(nums,0,ds,n,ans);
        return ans;
    }
};
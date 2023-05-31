class Solution { 
    void recur(vector<int>&nums, vector<vector<int>>&ans, vector<int>&ds, unordered_map<int,int> &mpp){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(mpp[nums[i]]==0 ||(i!=0 && nums[i]==nums[i-1])) continue;
            mpp[nums[i]]--;
            ds.push_back(nums[i]);
            recur(nums,ans,ds,mpp);
            ds.pop_back();
            mpp[nums[i]]++;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        unordered_map<int,int>mpp;
        vector<int>ds;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
            mpp[nums[i]]++;
        recur(nums,ans,ds,mpp);
        return ans;
    }
};
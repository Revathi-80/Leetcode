class Solution {
    void func(vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans,int freq[]){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(!freq[i]) {
                ds.push_back(nums[i]);
                freq[i]=1;
                func(nums,ds,ans,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>ds;
        vector<vector<int>>ans;
        int freq[n];
        for(int i=0;i<n;i++) freq[i]=0;
        func(nums,ds,ans,freq);
        return ans;
    }
};
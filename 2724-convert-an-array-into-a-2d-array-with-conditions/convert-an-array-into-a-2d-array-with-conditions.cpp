class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n= nums.size();
       vector<int>mpp(n+1);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++) {
            if(mpp[nums[i]] >=ans.size()) {
                ans.push_back({});
            }
            ans[mpp[nums[i]]].push_back(nums[i]);
            mpp[nums[i]]++;
        }
       return ans;
    }
};
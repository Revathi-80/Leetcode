class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>ans={nums[0]};
        int n=nums.size();  
        for(int i=1;i<n;i++){
         
            ans.push_back(ans.back()+nums[i]);
        }
        return ans;
    }
};
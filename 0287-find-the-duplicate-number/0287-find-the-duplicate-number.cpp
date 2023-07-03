class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
       sort(nums.begin(),nums.end());
        int ans=nums[0];
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};
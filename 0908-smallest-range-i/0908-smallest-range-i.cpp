class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        
        
        return max(0,nums[n-1]-k-nums[0]-k);
    }
};
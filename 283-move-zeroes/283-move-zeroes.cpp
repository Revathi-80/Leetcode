class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
       for(int slow=0,cur=0;cur<n;cur++){
           if(nums[cur]!=0)
           swap(nums[slow++],nums[cur]);
       }
    }
};
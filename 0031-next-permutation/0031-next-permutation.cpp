class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        //longest common prefix---find the break point
        int ind=-1;
        for(int i=n-2;i>=0;i--) {
            if(nums[i]<nums[i+1]) {
                ind=i;
                break;
            }
        }
        if(ind==-1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        // smallest which juuuuuust greater than nums[ind]
        for(int i=n-1;i>=ind;i--) {
            if(nums[ind]<nums[i]) {
                swap(nums[ind],nums[i]);
                break;
            }
        }
        //smallest possible permutation
        sort(nums.begin()+ind+1,nums.end());
    }
};
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n= nums.size(),sum=0,maxi=0;
        int i=0;
        unordered_map<int,int>mpp;
        while(i<k && i<n) {
            mpp[nums[i]]++;
            sum+=nums[i];
            i++;
        }
        if(mpp.size()==k) maxi=sum;
        while(i<nums.size()) {
            mpp[nums[i]]++;
            mpp[nums[i-k]]--;
            if(mpp[nums[i-k]]==0) mpp.erase(nums[i-k]);
            sum+=nums[i];
            sum-=nums[i-k];
            if(mpp.size()==k) maxi=max(sum,maxi);
            i++;
        }
        return maxi;
    }
};
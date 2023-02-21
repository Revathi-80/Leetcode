class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int ans;
        bool flag=false;
        for(int i=0;i<n-1;i++) {
            if(nums[i]!=nums[i+1]) {
                ans=nums[i];
                flag=true;
                break;
            }
            i++;
        }
        return flag?ans:nums[n-1];
    }
};
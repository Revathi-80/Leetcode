class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        int big=0,sbig=0,small=INT_MAX,ssmall=INT_MAX;
        for(int i=0;i<n;i++) {
            if(nums[i]>big){
                sbig=big;
                big=nums[i];
            }
            else {
                sbig= max(sbig,nums[i]);
            }
            if(nums[i]<small){
                ssmall=small;
                small=nums[i];
            }
            else {
                ssmall =min(ssmall,nums[i]);
            }
        }
        return ((big*sbig)-(small*ssmall));
    }
};
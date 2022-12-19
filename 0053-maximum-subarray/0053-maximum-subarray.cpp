class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxi=INT_MIN,current=0,n=nums.size();
        for(int i=0;i<n;i++){
           current = max(nums[i],current+nums[i]);
            if(current>maxi)
                maxi=current;
        }
        return maxi;
   }
};
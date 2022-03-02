class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN,just=0;
        for(int i=0;i<nums.size();i++){
            just+=nums[i];
            if(maxi<just)
            maxi=just;
            if(just<0){
                just=0;
            }
        }
        return maxi;
   }
};